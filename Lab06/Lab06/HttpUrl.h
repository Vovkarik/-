#pragma once
enum Protocol
{
	HTTP = 80,
	HTTPS = 443
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol = HTTP,
		unsigned short port = 80);
	std::string GetURL() const;
	std::string GetDomain() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;
private:
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;

	std::string ProtocolToString() const;
	Protocol StringToProtocol(std::string const& protocol) const;
};




