#include "stdafx.h"
#include "HttpUrl.h"
#include "UrlParsingError.h"

std::regex ex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)");
std::cmatch what;

CHttpUrl::CHttpUrl(std::string const& url)
{
	std::string urlCopy(url);
	if (std::regex_search(url.c_str(), what, ex)) {
		m_protocol = ParseProtocol(urlCopy);
		m_domain = ParseDomain(urlCopy);
		m_port = ParsePort(urlCopy);
		m_document = ParseDocument(urlCopy);
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
	return ProtocolToString() + "://" + m_domain + ":" + std::to_string(m_port) + m_document;;
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

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::ParseProtocol(std::string &url) const
{
	size_t position = url.find("://");
	if (position == std::string::npos)
	{
		throw CUrlParsingError("Protocol parsing error");
	}
	Protocol protocol = StringToProtocol(std::string(what[1].first, what[1].second));
	return protocol;
}

std::string CHttpUrl::ParseDomain(std::string &url) const
{
	
	std::string domain = std::string(what[2].first, what[2].second);
	if (domain.empty())
	{
		throw CUrlParsingError("Domain parsing error");
	}
	return domain;
}

unsigned short CHttpUrl::ParsePort(std::string &url) const
{
	unsigned short port;
	if (url[0] == ':')
	{
		try
		{
			port = boost::lexical_cast<unsigned short>(std::string(what[3].first, what[3].second));
		}
		catch (boost::bad_lexical_cast const& error)
		{
			throw CUrlParsingError(error.what());
		}
	}
	else
	{
		port = static_cast<unsigned short>(m_protocol);
	}
	return port;
}

std::string CHttpUrl::ParseDocument(std::string &url) const
{
	if (url.find(" ") != std::string::npos)
	{
		throw CUrlParsingError("Document parsing error");
	}
	std::string document = std::string(what[4].first, what[4].second);
	return document;
}