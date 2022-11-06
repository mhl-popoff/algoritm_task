// Java_or_C++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	bool flag_java = 0, flag_C = 0, flag_error = 0;

	char str[250];
	fin.getline(str, 250);

	char * p = str;
	char * start = str;
	char * i = str;
	
	while (*p != 0)
	{
		if ((*p >= 65) & (*p <= 90))
		{
			flag_java = 1;
			if (p == str)
			{
				flag_error = 1;
				break;
			}
		}
		if (*p == '_')
		{
			flag_C = 1;
			if (p == str || *p == *(p + 1) || *(p + 1) == 0)
			{
				flag_error = 1;
				break;
			}
		}
		p += 1;
	}
	
	p = start;

	if (flag_error == 1 || ((flag_C == 1) & (flag_java == 1)))
		fout << "Error!";
	else if (flag_C == 1)
	{
		while (*p != 0)
		{
			if ((*p == '_') & (*(p + 1) != '_'))
			{
				*(p + 1) -= 32;
				for (i = p; *(i - 1) != 0; i++)
				{
					*i = *(i + 1);
				}
			}
			fout << *p;
			p += 1;
		}
	}
	else if (flag_java == 1)
	{
		while (*p != 0)
		{
			if ((*p >= 65) & (*p <= 90))
			{
				*p += 32;
				fout << '_';
			}
			fout << *p;
			p += 1;
		}
	}
	else if ((flag_C == 0) & (flag_java == 0))
		fout << str;

    return 0;
}