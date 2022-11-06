#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n = 0;
	char str_1[100];
	char str_2[100];

	fin >> str_1;
	fin >> str_2;

	char * p_1 = str_1;
	char * start_1 = str_1;
	char * p_2 = str_2;

	while (*p_2 != 0)
	{
		while (*p_1 != 0)
		{
			if (*p_2 == *p_1)
				n++;
			p_1++;
		}
		p_1 = start_1;
		p_2++;
	}

	fout << n;

	return 0;
}