#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)//���������� ����� ��������
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}
//////////////////////////////////////////////////////////////////////////
// TODO: 1. ����������� ����� ToDouble() �������� �������
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}
//////////////////////////////////////////////////////////////////////////
// TODO: 2. ����������� ������� + � ������� -
//////////////////////////////////////////////////////////////////////////
const CRational CRational::operator +() const
{
	return *this;
}
const CRational CRational::operator -() const
{
	return CRational(-m_numerator, m_denominator);
}
//////////////////////////////////////////////////////////////////////////
// TODO: 3. ����������� �������� +
//////////////////////////////////////////////////////////////////////////
const CRational operator+(const CRational & left, const CRational & right)
{
	int resultNumerator = left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator();
	int resultDenominator = left.GetDenominator() * right.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}
//////////////////////////////////////////////////////////////////////////
// TODO: 4. ����������� �������� -
//////////////////////////////////////////////////////////////////////////
const CRational operator -(const CRational & left, const CRational & right)
{
	int resultNumerator = left.GetNumerator() * right.GetDenominator() - right.GetNumerator() * left.GetDenominator();
	int resultDenominator = left.GetDenominator() * right.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}
//////////////////////////////////////////////////////////////////////////
// TODO: 5. ����������� �������� +=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator +=(const CRational & summand)
{
	if (summand.GetNumerator() == 0)
	{
		return *this;
	}
	m_numerator = m_numerator * summand.GetDenominator() + m_denominator * summand.GetNumerator();
	m_denominator = m_denominator * summand.GetDenominator();
	Normalize();
	return *this;
}
//////////////////////////////////////////////////////////////////////////
// TODO: 6. ����������� �������� -=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator -=(const CRational & subtrahend)
{
	if (subtrahend.GetNumerator() == 0)
	{
		return *this;
	}
	m_numerator = m_numerator * subtrahend.GetDenominator() - m_denominator * subtrahend.GetNumerator();
	m_denominator = m_denominator * subtrahend.GetDenominator();
	Normalize();
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 7. ����������� �������� *
//////////////////////////////////////////////////////////////////////////
const CRational operator *(CRational const& left, CRational const& right)
{
	return CRational(left.GetNumerator() * right.GetNumerator(), left.GetDenominator() * right.GetDenominator());
}

//////////////////////////////////////////////////////////////////////////
// TODO: 8. ����������� �������� /
//////////////////////////////////////////////////////////////////////////
const CRational operator /(CRational const& left, CRational const& right)
{
	return CRational(left.GetNumerator() * right.GetDenominator(), left.GetDenominator() * right.GetNumerator());
}

//////////////////////////////////////////////////////////////////////////
// TODO: 9. ����������� �������� *=
//////////////////////////////////////////////////////////////////////////
CRational const& CRational::operator *=(CRational const& rational)
{
	*this = *this * rational;
	return *this;
}
//////////////////////////////////////////////////////////////////////////
// TODO: 10. ����������� �������� /=
//////////////////////////////////////////////////////////////////////////
CRational const& CRational::operator /=(CRational const& rational)
{
	*this = *this / rational;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 11. ����������� ��������� == � !=
//////////////////////////////////////////////////////////////////////////
const bool operator ==(CRational const & left, CRational const & right)
{
	CRational l = left, r = right;
	l.Normalize();
	r.Normalize();
	return (((l.GetNumerator() == r.GetNumerator()) && (r.GetDenominator() == l.GetDenominator())));
}

const bool operator !=(CRational const & left, CRational const & right)
{
	return !(left == right);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 12. ����������� ��������� <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
const bool operator <(CRational const & left, CRational const & right)
{
	return (left.GetNumerator() * right.GetDenominator() < right.GetNumerator() * left.GetDenominator());
}

const bool operator >=(CRational const & left, CRational const & right)
{
	return !(left < right);
}

const bool operator >(CRational const & left, CRational const & right)
{
	return (left.GetNumerator() * right.GetDenominator() > right.GetNumerator() * left.GetDenominator());
}

const bool operator <=(CRational const & left, CRational const & right)
{
	return !(left > right);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 13. ����������� �������� ������ ������������� ����� � �������� ����� 
//////////////////////////////////////////////////////////////////////////
std::ostream & operator <<(std::ostream & output, CRational & rational)
{
	output << rational.GetNumerator() << '/' << rational.GetDenominator();
	return output;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 14. ����������� �������� ����� ������������� ����� �� �������� ������ 
//////////////////////////////////////////////////////////////////////////
std::istream & operator >>(std::istream & input, CRational & rational)
{
	int numerator = 0;
	int denominator = 1;
	if ((input >> numerator) && (input.get() == '/') && (input >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		input.setstate(std::ios_base::failbit);
	}
	return input;
}

