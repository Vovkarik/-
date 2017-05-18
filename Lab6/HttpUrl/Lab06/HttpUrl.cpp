#include "stdafx.h"
#include "HttpUrl.h"
#include "UrlParsingError.h"

const unsigned short DEFAULT_HTTP_PORT = 80;
const unsigned short DEFAULT_HTTPS_PORT = 443;
const std::string HTTP_PROTOCOL = "http";
const std::string HTTPS_PROTOCOL = "https";

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw std::invalid_argument("Input is empty");
	}
	ParseUrl(url);
};

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol = Protocol::HTTP,
	unsigned short port = 80)
	: m_protocol(protocol)
	, m_domain(domain)
	, m_port(port)
{
	if (domain.empty())
	{
		throw std::invalid_argument("Invalid domain");
	}
	m_document = (document.empty() || document[0] != '/') ? document : document;
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol)
	: m_protocol(protocol)
	, m_domain(domain)
{
	if (domain.empty())
	{
		throw std::invalid_argument("Invalid domain");
	}
	m_document = (document.empty() || document[0] != '/') ? document : document;
	m_port = GetDefaultPort(m_protocol);
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document)
	: m_protocol(HTTP)
	, m_domain(domain)
{
	if (domain.empty())
	{
		throw std::invalid_argument("Invalid domain");
	}
	m_document = (document.empty() || document[0] != '/') ? document : document;
	m_port = GetDefaultPort(m_protocol);
}

std::string CHttpUrl::GetURL() const
{
	return ProtocolToString(m_protocol) + "://" + GetDomain() + "/" + m_document;;
};

std::string CHttpUrl::GetDomain() const
{
	std::string result = m_domain;
	if (!(m_protocol == Protocol::HTTP && m_port == 80 || m_protocol == Protocol::HTTPS && m_port == 443))
	{
		result += ":" + std::to_string(m_port);
	}
	return result;
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

void CHttpUrl::ParseUrl(std::string const& url)
{
	size_t pos = 0;
	ParseProtocol(url, pos);
	ParseDomain(url, pos);
	ParsePort(url, pos);
	ParseDocument(url, pos);
}

void CHttpUrl::ParseProtocol(std::string const& url, size_t & pos)
{
	std::string protocol;
	for (pos; pos < url.length(); ++pos)
	{
		if (url[pos] == ':')
		{
			break;
		}
		protocol += url[pos];
	}
	m_protocol = StringToProtocol(protocol);
	if (url.length() <= pos + 2 || url[pos] != ':' || url[pos + 1] != '/' || url[pos + 2] != '/')
	{
		throw CUrlParsingError("Invalid protocol");
	}
	pos += 3;
}

void CHttpUrl::ParseDomain(std::string const& url, size_t & pos)
{
	for (pos; pos < url.length(); ++pos)
	{
		if (url[pos] == '/' || url[pos] == ':')
		{
			break;
		}
		if (!(isalnum(url[pos]) || (url[pos] == '.') || (url[pos] == '-')))
		{
			throw CUrlParsingError("Domain contains unapropriate symbols");
		}
		m_domain += url[pos];
	}
	if (m_domain.empty())
	{
		throw CUrlParsingError("No domain specified");
	}
}

void CHttpUrl::ParsePort(std::string const& url, size_t & pos)
{
	if (url[pos] != ':')
	{
		m_port = GetDefaultPort(m_protocol);
		return;
	}
	pos++;
	std::string port;
	for (pos; pos < url.length(); ++pos)
	{
		if (url[pos] == '/')
		{
			break;
		}
		if (url[pos] == '-')
		{
			throw CUrlParsingError("Port can't be negative");
		}
		port += url[pos];
	}
	if (port.empty())
	{
		throw CUrlParsingError("Invalid port");
	}
	try
	{
		boost::lexical_cast<unsigned short>(port);
	}
	catch (boost::bad_lexical_cast &)
	{
		throw CUrlParsingError("Invalid port");
	}
	m_port = atoi(port.c_str());
}

void CHttpUrl::ParseDocument(std::string const& url, size_t & pos)
{
	if (url[pos] == '/')
	{
		pos++;
	}
	for (pos; pos < url.length(); ++pos)
	{
		if (url[pos] == ' ')
		{
			throw CUrlParsingError("Document contains spaces");
		}
		m_document += url[pos];
	}
}

unsigned short CHttpUrl::GetDefaultPort(Protocol const& protocol)
{
	if (protocol == Protocol::HTTPS)
	{
		return DEFAULT_HTTPS_PORT;
	}
	else
	{
		return DEFAULT_HTTP_PORT;
	}
}

std::string CHttpUrl::ProtocolToString(Protocol const& protocol) const
{
	if (protocol == Protocol::HTTP)
	{
		return HTTP_PROTOCOL;
	}
	else if (protocol == Protocol::HTTPS)
	{
		return HTTPS_PROTOCOL;
	}
	else
	{
		throw std::invalid_argument("Invalid protocol");
	}
}

Protocol CHttpUrl::StringToProtocol(std::string const& protocol) const
{
	if (protocol == HTTP_PROTOCOL)
	{
		return Protocol::HTTP;
	}
	else if (protocol == HTTPS_PROTOCOL)
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw CUrlParsingError("Invalid protocol");
	}
}