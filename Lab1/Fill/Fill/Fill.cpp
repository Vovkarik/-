// Fill.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"

const char MARKER = '0';
const char EMPTY_SPACE = ' ';
const char FILLING_SYMBOL = '.';

using namespace std;

bool ValidateArgumentsCount(size_t argc)
{
	if (argc != 3)
	{
		cout << "Invalid arguments count." << endl << "Usage: fill.exe <input file> <output file>" << endl;
		return false;
	}
	return true;
}

bool ValidateFiles(const ifstream & input, const ofstream & output)
{
	if (!input.is_open() || !output.is_open())
	{
		cout << "Failed to open file for reading" << endl;
		return false;
	}
	return true;
}

void ReadInput(ifstream & input, vector<string> & lines)
{
	string tempString;
	while (getline(input, tempString) && lines.size() < 100)
	{
		lines.push_back(tempString);
	}
}

void IdentifymarkersPositions(vector< pair<size_t, size_t> > & startPoints, vector<string> & lines)
{
	for (size_t i = 0; i < lines.size(); ++i)
	{
		size_t position = lines[i].find(MARKER);
		if (position != lines[i].npos)
		{
			startPoints.push_back(pair<size_t, size_t>(i, position));
		}
	}
}

void Fill(vector<string> & lines, size_t row, size_t col)
{
	if (row > 0 && col > 0 && row < lines.size() && lines[row][col] == EMPTY_SPACE)
	{
		lines[row][col] = FILLING_SYMBOL;
		Fill(lines, row + 1, col);
		Fill(lines, row - 1, col);
		Fill(lines, row, col - 1);
		Fill(lines, row, col + 1);
	}
}

void FindPointToFill(vector<string> & lines)
{
	vector< pair<size_t, size_t> > startPoints;
	IdentifymarkersPositions(startPoints, lines);
	for (size_t i = 0; i < startPoints.size(); i++)
	{
		pair<size_t, size_t> & point = startPoints[i];
		lines[point.first][point.second] = EMPTY_SPACE;
		Fill(lines, point.first, point.second);
		lines[point.first][point.second] = MARKER;
	}
}

void PrintCompletedImage(vector<string> & lines, ofstream & output)
{
	for (size_t i = 0; i < lines.size(); ++i)
	{
		output << lines[i] << endl;
	}
}

size_t main(size_t argc, char * argv[])
{
	setlocale(LC_ALL, "Rus");
	if (!ValidateArgumentsCount(argc))
	{
		return 1;
	}

	ifstream input(argv[1]);
	ofstream output(argv[2]);

	if (ValidateFiles(input, output))
	{
		vector<string> lines;
		ReadInput(input, lines);
		FindPointToFill(lines);
		PrintCompletedImage(lines, output);
	}
	return 0;
}
