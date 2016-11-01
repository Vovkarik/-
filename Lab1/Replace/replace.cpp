//6. replace.exe 
//Замена подстроки в текстовом файле на другую строку, запись результата в выходной файл(отличный от входного)
//Формат командной строки: replace.exe <input file> <output file> <search string> <replace string>
//Программа должна корректно обрабатывать ошибки, связанные с щткрытием входных и выходных файлов. Искомая строка не должна быть пустой
#include "stdafx.h"

using namespace std;

string Replace(string buffer, string searchKey, string replaceString, ofstream &out)
{
	string newString = "";
	size_t searchPosition = 0, replacePosition = buffer.find(searchKey);
	while (replacePosition != string::npos)
	{
		newString.append(buffer, searchPosition, replacePosition - searchPosition);
		newString += replaceString;
		searchPosition = replacePosition + searchKey.length();
		replacePosition = buffer.find(searchKey, searchPosition);
	}
	out << newString.append(buffer, searchPosition, replacePosition - searchPosition) << "\n";
	return newString;
}

int Errors(ifstream &in, ofstream &out, int numberOfArguments, string searchKey)
{
	if (!in.is_open())
	{
		cout << "Невозможно открыть входной файл! Проверьте правильность введенных данных\n";
		return 1;
	}
	if (!out.is_open())
	{
		cout << "Невозможно открыть выходной файл! Проверьте правильность введенных данных\n";
		return 1;
	}
	if (numberOfArguments != 5)
	{
		cout << "Неверное число аргументов\n" << "Проверьте, все ли аргументы(replace.exe <input file> <output file> <search string> <replace string>) введены\n";
		return 1;
	}
	if (in.peek() == ifstream::traits_type::eof())
	{
		cout << "Файл пустой";
		return 1;
	}
	/*if (searchKey.length() == 0)
	{
		cout << "Search string shouldn't be empty\n";
		return 1;
	}*/
	return 0;
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	Errors(in, out, argc, argv[3]);
	string replacement = argv[4], searchKey = argv[3], buffer;

	while (getline(in, buffer))
	{
		buffer = Replace(buffer, searchKey, replacement, out);
	}
	if (!out.flush())
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}
	return 0;
}