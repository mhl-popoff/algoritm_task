// Tank_in_city.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N, i, j;
	float length, width_tank, widht_streat;

	fin >> N;
	fin >> length >> width_tank >> widht_streat;

	if (widht_streat > width_tank)
	{
		fout << "\nYes";
		if (length * length + width_tank * width_tank < widht_streat * widht_streat)
		{
			fout << " Yes";
		}
		else fout << " No";
	}
	else fout << "No No";

    return 0;
}

