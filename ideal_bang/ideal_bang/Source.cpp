#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");

int main()
{
	char str[256], hold[256], max_str[256], start[256];
	max_str[0] = 0, hold[0] = 0;
	bool flag = 0;
	fin >> str;
	int n = strlen(str), index = 0, j, i;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1, flag = 0; j > i + index; j--)
		{
			if (str[i + index] == str[j])
			{
				hold[index] = str[j];
				index++;
				hold[j - i] = str[j];
				if (flag == 0)
					hold[j - i + 1] = 0;
				flag = 1;
			}
			else if (flag == 1)
			{
				index = 0;
				j++;
				hold[0] = 0;
				flag = 0;
			}
		}
		if (strlen(hold) % 2 != 0 && hold[0] != 0) hold[j - i] = str[j];
		if (strlen(hold) > strlen(max_str)) strcpy(max_str, hold);
		index = 0;
	}
	fout << max_str;
	return 0;
}
