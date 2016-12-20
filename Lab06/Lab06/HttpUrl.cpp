#include "stdafx.h"
#include "HttpUrl.h"
#include "UrlParsingError.h"

CHttpUrl::CHttpUrl(std::string const& url)
{
	boost::regex ex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)");
	boost::cmatch what;
	if (regex_search(url.c_str(), what, ex)) {
		size_t position = url.find("://");
		if (position == std::string::npos)
		{
			throw CUrlParsingError("Protocol parsing error");
		}
		m_protocol = StringToProtocol(std::string(what[1].first, what[1].second));
		position = url.find(":");
		if (position == std::string::npos)
		{
			position = url.find("/");
		}
		auto domain = url.substr(0, position);
		if (domain.empty())
		{
			throw CUrlParsingError("Domain parsing error");
		}
		m_domain = std::string(what[2].first, what[2].second);
		if (url[0] == ':')
		{
			auto endPos = url.find('/');
			auto portStr = url.substr(1, endPos - 1);
			if (portStr.empty()) throw CUrlParsingError("Port parsing error");
			try
			{
				m_port = boost::lexical_cast<unsigned short>(std::string(what[3].first, what[3].second));
			}
			catch (boost::bad_lexical_cast const& error)
			{
				throw CUrlParsingError(error.what());
			}
		}
		else
		{
			m_port = static_cast<unsigned short>(m_protocol);
		}
		if (url.find(" ") != std::string::npos)
		{
			throw CUrlParsingError("Document parsing error");
		}
		m_document = std::string(what[4].first, what[4].second);
	}
};

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port)
	:m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
	, m_port(port)
{
};

std::string CHttpUrl::GetURL() const
{
	return ProtocolToString() + "://" + m_domain + std::to_string(m_port) + m_document;;
};

std::string CHttpUrl::ProtocolToString() const
{
	std::string result;
	if (m_protocol == Protocol::HTTP)
	{
		result = "http";
	}
	else if (m_protocol == Protocol::HTTPS)
	{
		result = "https";
	}
	return result;
}

Protocol CHttpUrl::StringToProtocol(std::string const& protocol) const
{
	if (protocol == "http")
	{
		return Protocol::HTTP;
	}
	if (protocol == "https")
	{
		return Protocol::HTTPS;
	}
	throw CUrlParsingError("Invalid protocol");
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
};

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}