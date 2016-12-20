// Lab06.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HttpUrl.h"

int main()
{
	std::string urlstr;
	std::getline(std::cin, urlstr);
	CHttpUrl URL(urlstr);
	std::cout << URL.GetDomain() << std::endl;
	std::cout << URL.GetProtocol() << std::endl;
	std::cout << URL.GetPort() << std::endl;
	std::cout << URL.GetURL() << std::endl;
    return 0;
}

