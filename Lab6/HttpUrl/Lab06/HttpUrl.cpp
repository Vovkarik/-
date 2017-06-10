#include "stdafx.h"
#include "HttpUrl.h"
#include "UrlParsingError.h"

const unsigned short DEFAULT_HTTP_PORT = 80;
const unsigned short DEFAULT_HTTPS_PORT = 443;
const std::string HTTP_PROTOCOL = "http";
const std::string HTTPS_PROTOCOL = "https";
const std::string FORBIDDEN_SYMBOLS = " ~`!@#$%^&*;()+=}{][|\"'><?,	";

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Input is empty");
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
	, m_document(document)
{
	if (domain.empty())
	{
		throw CUrlParsingError("Invalid domain");
	}
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol)
	: m_protocol(protocol)
	, m_domain(domain)
	, m_document(document)
	, m_port(GetDefaultPort(m_protocol))
{
	if (domain.empty())
	{
		throw CUrlParsingError("Invalid domain");
	}
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document)
	: m_protocol(HTTP)
	, m_domain(domain)
	, m_document(document)
	, m_port(GetDefaultPort(m_protocol))
{
	if (domain.empty())
	{
		throw CUrlParsingError("Invalid domain");
	}
}

std::string CHttpUrl::GetURL() const
{
	std::string port = "";
	if (!(m_protocol == Protocol::HTTP && m_port == DEFAULT_HTTP_PORT || m_protocol == Protocol::HTTPS && m_port == DEFAULT_HTTPS_PORT))
	{
		port = ":" + std::to_string(m_port);
	}
	return ProtocolToString(m_protocol) + "://" + GetDomain() + port + "/" + m_document;;
};

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
	size_t delimiterPos = url.find(':', pos);
	std::string protocol(url, pos, delimiterPos - pos);
	m_protocol = StringToProtocol(protocol);
	pos += protocol.length();
	if (url.compare(pos, 3, "://") != 0)
	{
		throw CUrlParsingError("Invalid protocol");
	}
	pos += 3;
}

void CHttpUrl::ParseDomain(std::string const& url, size_t & pos)
{
	size_t delimiterPos = url.find(':', pos);
	if (delimiterPos == std::string::npos)
	{
		delimiterPos = url.find('/', pos);
	}
	if (url.find_first_of(FORBIDDEN_SYMBOLS, pos) != std::string::npos)
	{
		throw CUrlParsingError("Domain contains unapropriate symbols");
	}
	m_domain.assign(url, pos, delimiterPos - pos);
	pos += m_domain.length();
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
	if (url[pos] == '-')
	{
		throw CUrlParsingError("Port can't be negative");
	}
	size_t delimiterPos = url.find('/', pos);
	std::string port;
	port.append(url, pos, delimiterPos - pos);
	if (port.empty())
	{
		throw CUrlParsingError("Port is empty");
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
	pos += port.length();
}

void CHttpUrl::ParseDocument(std::string const& url, size_t & pos)
{
	if (pos < url.length())
	if (url[pos] == '/')
	{
		pos++;
	}
	if (url.find(' ', pos) != std::string::npos)
	{
		throw CUrlParsingError("Document contains spaces");
	}
	m_document.assign(url, pos);
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