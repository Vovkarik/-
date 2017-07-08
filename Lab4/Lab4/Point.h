#pragma once
class Point
{
public:
	Point() = default;
	Point(double x, double y);
	~Point() = default;
	std::string ToString() const;
	double x = 0.0;
	double y = 0.0;
};

std::istream & operator >> (std::istream & input, Point & point);

