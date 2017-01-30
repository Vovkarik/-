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
	std::string GetDocument() const;
	std::string ProtocolToString() const;
private:
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;

	Protocol ParseProtocol(std::string & url) const;
	std::string ParseDomain(std::string & url) const;
	unsigned short ParsePort(std::string & url) const;
	std::string CHttpUrl::ParseDocument(std::string &url) const;
	Protocol StringToProtocol(std::string const& protocol) const; 
};




