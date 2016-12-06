#include "stdafx.h"
#include "ProcessVector.h"

std::vector<double> GetNumbers(std::string const& inputString)
{
	std::vector<double> numbers;
	if (!inputString.empty())
	{
		std::vector<std::string> splittedNumbers;
		boost::split(splittedNumbers, inputString, boost::is_any_of(" "));
		std::transform(splittedNumbers.begin(), splittedNumbers.end(), std::back_inserter(numbers), boost::lexical_cast<int, std::string>);
	}
	return numbers;
}

void OutputNumbers(std::vector<double> const& numbers)
{
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, " "));
}

void ProcessVector(std::vector<double> & numbers)
{
	if (!numbers.empty())
	{
		std::sort(numbers.begin(), numbers.end());
		double divider = numbers.back();
		transform(numbers.begin(), numbers.end(), numbers.begin(), ([&](double a) {return a / divider; }));
		OutputNumbers(numbers);
	}
}