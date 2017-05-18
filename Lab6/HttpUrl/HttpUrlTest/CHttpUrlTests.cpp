#include "stdafx.h"
#include "../Lab06/HttpUrl.h"
#include "../Lab06/UrlParsingError.h"

BOOST_AUTO_TEST_SUITE(CHttpURL)

	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_string)
	
		BOOST_AUTO_TEST_CASE(can_assign_url_by_string_method)
		{
			CHttpUrl googleUrl("http://www.google.com/index.html");
			BOOST_CHECK_EQUAL(googleUrl.GetDocument(), "index.html");
			BOOST_CHECK_EQUAL(googleUrl.GetProtocol(), HTTP);
			BOOST_CHECK_EQUAL(googleUrl.GetDomain(), "www.google.com");
			BOOST_CHECK_EQUAL(googleUrl.GetPort(), 80);
		}
		
		BOOST_AUTO_TEST_CASE(if_scheme_incorrect_then_class_throw_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("htts://domain.com/document"), CUrlParsingError);
		}
		
		BOOST_AUTO_TEST_CASE(if_scheme_delimether_is_incorrect_then_class_throw_parsing_error_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("htts:/domain.com/document"), CUrlParsingError);
		}
		
		BOOST_AUTO_TEST_CASE(if_domain_is_empty_then_class_throw_invalid_args_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("https:///domain"), CUrlParsingError);
		}
		
		BOOST_AUTO_TEST_CASE(if_domain_is_equal_space_then_class_throw_invalid_args_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("https://     /document"), CUrlParsingError);
		}
		
		BOOST_AUTO_TEST_CASE(if_domain_contain_space_then_class_throw_invalid_args_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("https://domain .com/document"), CUrlParsingError);
		}
		
		BOOST_AUTO_TEST_CASE(if_document_is_empty_class_do_not_throw_exception)
		{
			BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://google.com/"));
			BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://google.com"));
		}
		
		BOOST_AUTO_TEST_CASE(if_document_is_empty_then_get_doc_returns_empty_doc)
		{
			CHttpUrl url1("https://google.com/");
			BOOST_CHECK_EQUAL(url1.GetDocument(), "");
		
			CHttpUrl url2("https://google.com");
			BOOST_CHECK_EQUAL(url2.GetDocument(), "");
		}
		
		BOOST_AUTO_TEST_CASE(if_url_contains_non_empty_document_get_doc_returns_him)
		{
			CHttpUrl url("http://google.com/search/document.txt");
			BOOST_CHECK_EQUAL(url.GetDocument(), "search/document.txt");
		}
		
		BOOST_AUTO_TEST_CASE(if_url_contains_port_then_port_will_be_different_from_standart)
		{
			CHttpUrl url("http://google.com:42/search/document.txt");
			BOOST_CHECK_EQUAL(url.GetPort(), 42u);
		}
		
		BOOST_AUTO_TEST_CASE(port_may_be_final_element)
		{
			CHttpUrl url("http://domain.com:42");
			BOOST_CHECK_EQUAL(url.GetPort(), 42u);
		}
		
		BOOST_AUTO_TEST_CASE(if_there_is_a_colon_and_no_port_class_throw_excpt)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("http://domain.com:"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl url("http://domain.com:/document"), CUrlParsingError);
		}
		
	BOOST_AUTO_TEST_SUITE_END()
	
	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_components)
		
		BOOST_AUTO_TEST_CASE(can_parse_document_right)
		{
			CHttpUrl url1("domain.com", "");
			BOOST_CHECK_EQUAL(url1.GetDocument(), "");
		
			CHttpUrl url2("domain.com", "document/something.txt");
			BOOST_CHECK_EQUAL(url2.GetDocument(), "document/something.txt");
		}
		
		BOOST_AUTO_TEST_CASE(default_protocol_is_http_and_default_port_is_80)
		{
			CHttpUrl url("domain.com", "document/something.txt");
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTP);
			BOOST_CHECK_EQUAL(url.GetPort(), 80u);
		}
		
		BOOST_AUTO_TEST_CASE(can_explicitly_specify_the_protocol)
		{
			CHttpUrl url("domain.com", "document/something.txt", Protocol::HTTPS);
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK_EQUAL(url.GetPort(), 443u);
		}
		
		BOOST_AUTO_TEST_CASE(can_explicitly_specify_the_port_of_fourth_parameter)
		{
			CHttpUrl url("domain.com", "document/something.txt", Protocol::HTTPS, 05);
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK_EQUAL(url.GetPort(), 5u);
		}
	
	BOOST_AUTO_TEST_SUITE_END()
	
	struct initialize_url_
	{
		initialize_url_()
			: urlStr("https://domain.com/document/something.txt")
			, url(urlStr)
		{};
	
		std::string urlStr;
		CHttpUrl url;
	};
	
	BOOST_FIXTURE_TEST_SUITE(before_initialized_url, initialize_url_)
	
		BOOST_AUTO_TEST_CASE(can_get_the_protocol)
		{
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
		}
		
		BOOST_AUTO_TEST_CASE(as_our_protocol_has_equal_that_https_then_port_is_equal_443)
		{
			BOOST_CHECK_EQUAL(url.GetPort(), 443u);
		}
		
		BOOST_AUTO_TEST_CASE(can_get_the_domain_name)
		{
			BOOST_CHECK_EQUAL(url.GetDomain(), "domain.com");
		}
		
		BOOST_AUTO_TEST_CASE(can_get_the_document)
		{
			BOOST_CHECK_EQUAL(url.GetDocument(), "document/something.txt");
		}
		
		BOOST_AUTO_TEST_CASE(can_get_the_url)
		{
			BOOST_CHECK_EQUAL(url.GetURL(), urlStr);
		}
		
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()