// HtmlDecodeTests.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "..\HtmlDecode\HtmlDecode.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(HtmlDecode_function)
	BOOST_AUTO_TEST_CASE(returns_empty_string_if_input_empty_string)
	{
		BOOST_CHECK_EQUAL(HtmlDecode(""), "");
	}

BOOST_AUTO_TEST_CASE(returns_empty_string_if_input_empty_strin2g)
{
	BOOST_CHECK_EQUAL(HtmlDecode("&amp;amp;"), "&amp;");
}

	BOOST_AUTO_TEST_CASE(returns_source_string_if_it_does_not_have_HTML_syntax)
	{
		string strWithoutHtmlSyntax = "This is the string without HTML syntax";
		BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlSyntax), strWithoutHtmlSyntax);
	}

	BOOST_AUTO_TEST_CASE(returns_source_string_if_HTML_syntax_are_wrong)
	{
		string strWithoutHtmlSyntax = "This &ltis&gt the string without &quotHTML&quot syntax";
		BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlSyntax), strWithoutHtmlSyntax);
	}

	BOOST_AUTO_TEST_CASE(replace_syntax)
	{
		string strWithHtmlSyntax = "This&apos;s the &lt;string&gt; with &quot;HTML&quot; syntax";
		string requiredStr = "This's the <string> with \"HTML\" syntax";
		BOOST_CHECK_EQUAL(HtmlDecode(strWithHtmlSyntax), requiredStr);
	}
BOOST_AUTO_TEST_SUITE_END()