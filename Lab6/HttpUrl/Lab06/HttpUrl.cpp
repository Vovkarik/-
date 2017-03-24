#include "stdafx.h"
#include "HttpUrl.h"
#include "UrlParsingError.h"

CHttpUrl::CHttpUrl(std::string const& url)
{
	std::string urlCopy(url);
	m_protocol = ParseProtocol(urlCopy);
	m_domain = ParseDomain(urlCopy);
	m_port = ParsePort(urlCopy);
	m_document = ParseDocument(urlCopy);
};

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port)
	:m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
	, m_port(port)(_CRT_CONST_CORRECT_OVERLOADS)
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
	Protocol protocol;
	if (url.substr(0, 7) == "http://" || url.substr(0, 8) == "https://")
	{
		if (url.substr(0, 7) == "http://")
		{
			protocol = HTTP;
			url = url.substr(7);
		}
		else
		{
			protocol = HTTPS;
			url = url.substr(8);
		}
	}
	else
	{
		throw CUrlParsingError("Protocol parsing error");
	}
	return protocol;
}

std::string CHttpUrl::ParseDomain(std::string &url) const
{
	std::string domain;
	auto domainEnd = url.find(':');
	if (domainEnd == std::string::npos)
	{
		domainEnd = url.find("/");
		domain = url.substr(0, domainEnd);
	}
	else
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
		size_t endOfPort = url.find('/');
		std::string portString = url.substr(1, endOfPort - 1);
		url = url.substr(endOfPort);
		if (portString.empty()) throw CUrlParsingError("Port parsing error");
		try
		{
			port = boost::lexical_cast<unsigned short>(portString);
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

::string CHttpUrl::ParseDocument(std::string &url) const
{
	std::string document;gmtime
	
	(std::regex_search(url, what, ex))
	{
		document = std::string(what[4].first, what[4].second);
	}
	else
	{
		throw CUrlParsingError("Document parsing error");
	}
	return document;
}