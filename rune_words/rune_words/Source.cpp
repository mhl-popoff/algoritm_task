#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	char str[1000000];
	int n = 1;
	fin >> str;
	char * p = str;

	while (*p != 0)
	{
		if ((p == str) & ((*p < 65) || (*p > 90)))
		{
			fout << "No";
			return 0;
		}
		else if ((*p >= 97) & (*p <= 122))
		{
			n++;
			if ((n < 2) || (n > 4))
			{
				fout << "No";
				return 0;
			}
		}
		else if ((*p >= 65) & (*p <= 90))
		{
			if (((*(p + 1) >= 65) & (*(p + 1) <= 90)) || (*(p + 1) == 0))
			{
				fout << "No";
				return 0;
			}
			n = 1;
		}
		p++;
	}

	fout << "Yes";

	return 0;
}