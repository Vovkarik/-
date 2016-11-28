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

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////
const CRational operator+(const CRational & lRational, const CRational & rRational)
{
	int resultNumerator = lRational.GetNumerator() * rRational.GetDenominator() + rRational.GetNumerator() * lRational.GetDenominator();
	int resultDenominator = lRational.GetDenominator() * rRational.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
const CRational operator-(const CRational & lRational, const CRational & rRational)
{
	int resultNumerator = lRational.GetNumerator() * rRational.GetDenominator() - rRational.GetNumerator() * lRational.GetDenominator();
	int resultDenominator = lRational.GetDenominator() * rRational.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator+=(const CRational & subtrahend)
{
	if (subtrahend.GetNumerator() == 0)
	{
		return *this;
	}
	m_numerator = m_numerator * subtrahend.GetDenominator() + m_denominator * subtrahend.GetNumerator();
	m_denominator = m_denominator * subtrahend.GetDenominator();
	Normalize();
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator-=(const CRational & subtrahend)
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
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////
const bool operator ==(CRational const & left, CRational const & right)
{
	return (left.GetNumerator() == right.GetNumerator;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
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
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////
std::ostream & operator << (std::ostream & output, CRational & rat)
{
	output << rat.GetNumerator() << '/' << rat.GetDenominator();
	return output;
}




//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////
std::istream & operator >> (std::istream & input, CRational & rat)
{
	int numerator = 0;
	int denominator = 1;
	if ((input >> numerator) && (input.get() == '/') && (input >> denominator))
	{
		rat = CRational(numerator, denominator);
	}
	else
	{
		input.setstate(std::ios_base::failbit);
	}
	return input;
}

