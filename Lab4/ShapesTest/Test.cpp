#include "stdafx.h"
#include "../Lab4/Circle.h"
#include "../Lab4/LineSegment.h"
#include "../Lab4/Rectangle.h"
#include "../Lab4/Point.h"
#include "../Lab4/Triangle.h"

void VerifyPoint(Point const& point, float expectedX, float expectedY)
{
	BOOST_CHECK_CLOSE_FRACTION(point.x, expectedX, FLT_EPSILON);
	BOOST_CHECK_CLOSE_FRACTION(point.y, expectedY, FLT_EPSILON);
};

BOOST_AUTO_TEST_SUITE(Point_class)

BOOST_AUTO_TEST_CASE(can_explicit_init_point)
{
	Point point = { 10.f, 25.8f };
	VerifyPoint(point, 10.f, 25.8f);
}
BOOST_AUTO_TEST_CASE(can_init_point_via_constructor)
{
	Point point(10.f, 25.8f);
	VerifyPoint(point, 10.f, 25.8f);
}
BOOST_AUTO_TEST_CASE(can_init_point_via_fields)
{
	Point point;
	point.x = 10.f;
	point.y = 25.8f;
	VerifyPoint(point, 10.f, 25.8f);
}
BOOST_AUTO_TEST_CASE(can_get_string_value)
{
	Point point(10.f, 20.f);
	BOOST_CHECK_EQUAL(point.ToString(), "(10.000000, 20.000000)");
}
BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
{
	Point point;
	std::stringstream input("10 20");
	input >> point;
	VerifyPoint(point, 10.f, 20.f);
}

BOOST_AUTO_TEST_SUITE_END()

struct CircleFixture
{
	CCircle circle;
	CircleFixture()
		:circle({ 5, 10 }, 5, "000000", "0000FF")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Circle_class, CircleFixture)

BOOST_AUTO_TEST_CASE(has_correct_area)
{
	BOOST_CHECK_CLOSE_FRACTION(circle.GetArea(), boost::math::constants::pi<float>() * 5.f * 5.f, FLT_EPSILON);
}
BOOST_AUTO_TEST_CASE(has_correct_perimeter)
{
	BOOST_CHECK_CLOSE_FRACTION(circle.GetPerimeter(), boost::math::constants::two_pi<float>() * 5.f, FLT_EPSILON);
}
BOOST_AUTO_TEST_CASE(has_correct_outline_color)
{
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), "000000");
}
BOOST_AUTO_TEST_CASE(has_correct_fill_color)
{
	BOOST_CHECK_EQUAL(circle.GetFillColor(), "0000FF");
}

BOOST_AUTO_TEST_CASE(has_correct_radius)
{
	BOOST_CHECK_EQUAL(circle.GetRadius(), 5);
}
BOOST_AUTO_TEST_CASE(to_string_print_correct_data)
{
	std::stringstream expectedStr;
	expectedStr << "\n" << "Circle" << "\n"
		<< "Outline color: 000000" << "\n"
		<< "Fill color: 0000FF" << "\n"
		<< "Area: " << (boost::math::constants::pi<long double>() * 5.0f * 5.0f) << 0 << 0 << "\n"
		<< "Perimeter: " << (boost::math::constants::two_pi<long double>() * 5.0f) << 0 << 0 << "\n"
		<< "Center: (5.000000, 10.000000)" << "\n"
		<< "Radius: 5.000000" << "\n";
	BOOST_CHECK_EQUAL(circle.ToString(), expectedStr.str());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Circle_class)

BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
{
	Point center;
	double radius = 0;
	std::string outlineColor = "", fillColor = "";
	CCircle circle(center, radius, outlineColor, fillColor);
	std::stringstream input("0 0 10 010101 FAFAFA");
	BOOST_CHECK(input >> circle);
	BOOST_CHECK_EQUAL(circle.GetRadius(), 10);
	BOOST_CHECK_EQUAL(circle.GetArea(), M_PI * 10 * 10);
	BOOST_CHECK_EQUAL(circle.GetPerimeter(), 2 * M_PI * 10);
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), "010101");
	BOOST_CHECK_EQUAL(circle.GetFillColor(), "FAFAFA");
}

BOOST_AUTO_TEST_SUITE_END()

struct LineSegmentFixture
{
	CLineSegment line;
	LineSegmentFixture()
		:line({ 5, 10 }, { 9, 7 }, "000000")
	{}
};

BOOST_FIXTURE_TEST_SUITE(LineSegment_class, LineSegmentFixture)

BOOST_AUTO_TEST_CASE(has_zero_area)
{
	BOOST_CHECK_EQUAL(line.GetArea(), 0);
}
BOOST_AUTO_TEST_CASE(has_correct_perimeter)
{
	BOOST_CHECK_EQUAL(line.GetPerimeter(), 5);
}
BOOST_AUTO_TEST_CASE(has_correct_outline_color)
{
	BOOST_CHECK_EQUAL(line.GetOutlineColor(), "000000");
}
BOOST_AUTO_TEST_CASE(has_correct_start_point)
{
	VerifyPoint(line.GetStartPoint(), 5, 10);
}
BOOST_AUTO_TEST_CASE(has_correct_end_point)
{
	VerifyPoint(line.GetEndPoint(), 9, 7);
}
BOOST_AUTO_TEST_CASE(to_string_print_correct_data)
{
	std::stringstream expectedStr;
	expectedStr << "\n" << "Line" << "\n"
		<< "Outline color: 000000" << "\n"
		<< "Area: 0" << "\n"
		<< "Perimeter: 5.000000" << "\n"
		<< "Start point: (5.000000, 10.000000)" << "\n"
		<< "End point: (9.000000, 7.000000)" << "\n";
	BOOST_CHECK_EQUAL(line.ToString(), expectedStr.str());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(LineSegment_class)

BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
{
	std::string outlineColor = "";
	Point startPoint, endPoint;
	CLineSegment line(startPoint, endPoint, outlineColor);
	std::stringstream input("0 0 0 5 010101");
	BOOST_CHECK(input >> line);
	VerifyPoint(line.GetStartPoint(), 0.f, 0.f);
	VerifyPoint(line.GetEndPoint(), 0.f, 5.f);
	BOOST_CHECK_EQUAL(line.GetArea(), 0);
	BOOST_CHECK_EQUAL(line.GetPerimeter(), 5);
	BOOST_CHECK_EQUAL(line.GetOutlineColor(), "010101");
}

BOOST_AUTO_TEST_SUITE_END()

struct RectangleFixture
{
	CRectangle rectangle;
	RectangleFixture()
		:rectangle({ 1, 1 }, 50, 100, "000000", "0000FF")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Rectangle_class, RectangleFixture)

BOOST_AUTO_TEST_CASE(has_correct_area)
{
	BOOST_CHECK_CLOSE_FRACTION(rectangle.GetArea(), 50.f * 100.f, FLT_EPSILON);
}
BOOST_AUTO_TEST_CASE(has_correct_perimeter)
{
	BOOST_CHECK_CLOSE_FRACTION(rectangle.GetPerimeter(), (50 + 100) * 2.f, FLT_EPSILON);
}
BOOST_AUTO_TEST_CASE(has_correct_outline_color)
{
	BOOST_CHECK_EQUAL(rectangle.GetOutlineColor(), "000000");
}
BOOST_AUTO_TEST_CASE(has_correct_fill_color)
{
	BOOST_CHECK_EQUAL(rectangle.GetFillColor(), "0000FF");
}
BOOST_AUTO_TEST_CASE(has_correct_left_top)
{
	VerifyPoint(rectangle.GetLeftTop(), 1, 1);
}
BOOST_AUTO_TEST_CASE(has_correct_right_bottom)
{
	VerifyPoint(rectangle.GetRightBottom(), 1 + 50, 1 + 100);
}
BOOST_AUTO_TEST_CASE(has_correct_width)
{
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 50);
}
BOOST_AUTO_TEST_CASE(has_correct_height)
{
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 100);
}
BOOST_AUTO_TEST_CASE(to_string_print_correct_data)
{
	std::stringstream expectedStr;
	expectedStr << "\n" << "Rectangle" << "\n"
		<< "Outline color: 000000" << "\n"
		<< "Fill color: 0000FF" << "\n"
		<< "Area: 5000" << "\n"
		<< "Perimeter: 300.000000" << "\n"
		<< "LeftTop: (1.000000, 1.000000)" << "\n"
		<< "RightBottom: (51.000000, 101.000000)" << "\n"
		<< "Width: 50.000000" << "\n"
		<< "Height: 100.000000" << "\n";
	BOOST_CHECK_EQUAL(rectangle.ToString(), expectedStr.str());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Rectangle_class)

BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
{
	Point leftTop;
	double width = 0, height = 0;
	std::string outlineColor = "", fillColor = "";
	CRectangle rectangle(leftTop, width, height, outlineColor, fillColor);
	std::stringstream input("1 1 50 100 010101 FAFAFA");
	BOOST_CHECK(input >> rectangle);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 50);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 100);
	VerifyPoint(rectangle.GetLeftTop(), 1.f, 1.f);
	VerifyPoint(rectangle.GetRightBottom(), 51.f, 101.f);
	BOOST_CHECK_EQUAL(rectangle.GetArea(), 5000);
	BOOST_CHECK_EQUAL(rectangle.GetPerimeter(), 300);
	BOOST_CHECK_EQUAL(rectangle.GetOutlineColor(), "010101");
	BOOST_CHECK_EQUAL(rectangle.GetFillColor(), "FAFAFA");
}

BOOST_AUTO_TEST_SUITE_END()

struct TriangleFixture
{
	CTriangle triangle;
	TriangleFixture()
		:triangle({ 5, 10 }, { 9, 7 }, { 6, 8 }, "000000", "0000FF")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Triangle_class, TriangleFixture)

BOOST_AUTO_TEST_CASE(has_correct_vertex1)
{
	VerifyPoint(triangle.GetVertex1(), 5, 10);
}
BOOST_AUTO_TEST_CASE(has_correct_vertex2)
{
	VerifyPoint(triangle.GetVertex2(), 9, 7);
}
BOOST_AUTO_TEST_CASE(has_correct_vertex3)
{
	VerifyPoint(triangle.GetVertex3(), 6, 8);
}
BOOST_AUTO_TEST_CASE(has_correct_side_length)
{
	BOOST_CHECK_EQUAL(triangle.GetSideLength(triangle.GetVertex1(), triangle.GetVertex2()), 5);
}
BOOST_AUTO_TEST_CASE(has_correct_perimeter)
{
	BOOST_CHECK_CLOSE_FRACTION(triangle.GetPerimeter(), 10.39834563766817f, FLT_EPSILON);
}
BOOST_AUTO_TEST_CASE(has_correct_area)
{
	BOOST_CHECK_CLOSE_FRACTION(triangle.GetArea(), 2.5f, FLT_EPSILON);
}
BOOST_AUTO_TEST_CASE(has_correct_outline_color)
{
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), "000000");
}
BOOST_AUTO_TEST_CASE(has_correct_fill_color)
{
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), "0000FF");
}
BOOST_AUTO_TEST_CASE(to_string_print_correct_data)
{
	std::stringstream expectedStr;
	expectedStr << "\n" << "Triangle" << "\n"
		<< "Outline color: 000000" << "\n"
		<< "Fill color: 0000FF" << "\n"
		<< "Area: 2.5" << "\n"
		<< "Perimeter: 10.3983" << "\n"
		<< "Vertex 1: (5.000000, 10.000000)" << "\n"
		<< "Vertex 2: (9.000000, 7.000000)" << "\n"
		<< "Vertex 3: (6.000000, 8.000000)" << "\n";
	BOOST_CHECK_EQUAL(triangle.ToString(), expectedStr.str());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Triangle_class)

BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
{
	Point v1, v2, v3;
	std::string outlineColor = "", fillColor = "";
	CTriangle triangle(v1, v2, v3, outlineColor, fillColor);
	std::stringstream input("0 0 0 4 5 0 010101 FAFAFA");
	BOOST_CHECK(input >> triangle);
	VerifyPoint(triangle.GetVertex1(), 0.f, 0.f);
	VerifyPoint(triangle.GetVertex2(), 0.f, 4.f);
	VerifyPoint(triangle.GetVertex3(), 5.f, 0.f);
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), "010101");
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), "FAFAFA");
}

BOOST_AUTO_TEST_SUITE_END()