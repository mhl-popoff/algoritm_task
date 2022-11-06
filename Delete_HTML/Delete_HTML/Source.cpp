#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");



int main()
{

	string text;
	int index = 0;
	bool flag_0, flag_1, flag_2, flag_3;

	getline(fin, text, '\0');

	while (text[index] != 0)
	{
		if (text[index] == '\n')
			text[index] = ' ';
		else if (text[index] == '<')
		{
			flag_1 = isalpha(text[index + 1]);
			flag_2 = isalpha(text[index + 2]);
			flag_3 = isalpha(text[index + 3]);
			if (flag_1 == 1 && flag_2 == 0)
				text.erase(index, 3);
			else if (flag_1 == 0 && flag_2 == 1 && flag_3 == 0)
				text.erase(index, 4);
			else if (flag_1 == 1 && flag_2 == 1 && flag_3 == 0)
			{
				text.erase(index, 3);
				text[index] = '\n';
			}
		}
		index++;
	}

	fout << text;

	return 0;
}