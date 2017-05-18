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
		Protocol protocol,
		unsigned short port);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol);
	CHttpUrl(
		std::string const& domain,
		std::string const& document);
	std::string GetURL() const;
	std::string GetDomain() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;
	std::string GetDocument() const;
	std::string ProtocolToString(Protocol const& protocol) const;
private:
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;

	unsigned short GetDefaultPort(Protocol const& protocol);
	void ParseUrl(std::string const& url);
	void ParseProtocol(std::string const& url, size_t & pos);
	void ParseDomain(std::string const& url, size_t & pos);
	void ParsePort(std::string const& url, size_t & pos);
	void ParseDocument(std::string const&url, size_t & pos);
	Protocol StringToProtocol(std::string const& protocol) const; 
};




