// HtmlDecode.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
const std::map <std::string, std::string> decodeKeys = {{ "&quot;", "\"" },
														{ "&apos;", "Т" },
														{ "&lt;", "<" },
														{ "&gt;", ">" },
														{ "&amp;", "&" }};

std::string HtmlDecode(const std::string &html)
{
	std::string result;
	auto it = decodeKeys.begin();
	for (size_t textIndex = 0; textIndex < html.length(); ++textIndex)
	{
		bool wasReplace = false;
		if (html[textIndex] == '&')
		{
			for (auto it = decodeKeys.begin(); it != decodeKeys.end(); ++it)
			{
				if (html.find(it->first.c_str(), textIndex, it->first.length()) == textIndex)
				{
					result += it->second;
					textIndex += it->first.length() - 1;
					wasReplace = true;
				}
			}
		}
		if (!wasReplace)
		{
			result += html[textIndex];
		}
	}
	return result;
}