// Replace.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

bool IsValidArgumentsCount(const int & argc)
{
	return (argc == 5);
}

bool IsFileExists(const ifstream &file)
{
	return file.good();
}

bool IsFileEmpty(ifstream &file)
{
	return file.peek() == ifstream::traits_type::eof();
}

bool IsValidInputOutputFiles(char* argv[], ifstream &inputFile, const ofstream &outputFile)
{
	if (!IsFileExists(inputFile))
	{
		cout << "File \"" << argv[1] << "\" not exists" << "\n";
		return false;
	}
	if (IsFileEmpty(inputFile))
	{
		cout << "File \"" << argv[1] << "\" is empty" << "\n";
		return false;
	}
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing" << "\n";
		return false;
	}
	return true;
}

bool IsDataEmpty(string const& buffer, string const& searchString, string const& replaceString)
{
	return (buffer.size() != 0) && (searchString.length() != 0) && (replaceString.length() != 0);
}

void Replace(ifstream & inputFile, string const& searchString, string const& replaceString)
{
	string buffer;
	while (!inputFile.eof())
	{
		getline(inputFile, buffer);
		if (IsDataEmpty(buffer, searchString, replaceString)) boost::replace_all(buffer, searchString, replaceString);
		cout << buffer << endl;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (!IsValidArgumentsCount(argc))
	{
		cout << "replace.exe using: <input file> <output file> <search string> <replace string>" << "\n";
		return 1;
	}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	if (!IsValidInputOutputFiles(argv, inputFile, outputFile))
	{
		return 1;
	}

	string stringToSearch = argv[3];
	string stringToReplace = argv[4];

	if (stringToSearch.empty())
	{
		cout << "Search string isn't set" << "\n";
		return 1;
	}

	Replace(inputFile, stringToSearch, stringToReplace);

	return 0;
}