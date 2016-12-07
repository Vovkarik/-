#include "stdafx.h"
#include "HtmlDecode.h"

int main()
{
	std::string htmlString, resultString;
	std::cin >> htmlString;
	resultString = HtmlDecode(htmlString);
	std::cout << resultString;
	return 0;
}