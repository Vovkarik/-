//6. replace.exe 
//Замена подстроки в текстовом файле на другую строку, запись результата в выходной файл(отличный от входного)
//Формат командной строки: replace.exe <input file> <output file> <search string> <replace string>
//Программа должна корректно обрабатывать ошибки, связанные с щткрытием входных и выходных файлов. Искомая строка не должна быть пустой
#include "stdafx.h"

using namespace std;

void replace(ifstream &in, ofstream &out, char* searchKey, string stringToReplace)
{
	string buffer;
	int keyWordPos;
	while (getline(in, buffer))
	{
		keyWordPos = buffer.find(searchKey);
		if (keyWordPos != string::npos)
		{
			buffer.replace(keyWordPos, strlen(searchKey), stringToReplace);
		}
		out << buffer << endl;
	}
	in.close();
	out.close();
}

int errors(ifstream &in, ofstream &out, int numberOfArguments)
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
	if (numberOfArguments < 4)
	{
		cout << "Введено менее 4рех аргументов";
		return 1;
	}
	if (in.peek() == ifstream::traits_type::eof())
	{
		cout << "Файл пустой";
		return 1;
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	errors(in, out, argc);
	replace(in, out, argv[3], argv[4]) ;
	return 0;
}