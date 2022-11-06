#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");

int main()
{
	int n, sist_schis, temp, index = 0;
	bool flag = 0;
	vector<char> str1, str2, str_sum;
	char hold[102];
	fin >> sist_schis >> hold;
	n = strlen(hold);
	for (int i = 0; i < n; i++)
		str1.push_back(hold[i]);
	fin >> hold;
	n = strlen(hold);
	for (int i = 0; i < n; i++)
		str2.push_back(hold[i]);
	if (str1.size() < str2.size()) swap(str1, str2);
	while (str1.size() != str2.size())
		str2.insert(str2.begin(), '0');
	n = str1.size();
	for (int i = n - 1; i >= 0; i--)
	{
		if (flag == 1)
		{
			flag = 0;
			temp = str1[i] - 48 + str2[i] - 48 + 1;
		}
		else temp = str1[i] - 48 + str2[i] - 48;
		if (temp >= sist_schis)	{
			temp -= sist_schis;
			flag = 1;
		}
		str_sum.push_back((char)(temp + 48));
	}
	if (flag == 1)
	{
		str_sum.push_back((char)(49));
		str1.insert(str1.begin(), '0');
		str2.insert(str2.begin(), '0');
	}
	reverse(str_sum.begin(), str_sum.end());
	
	for (int i = 0, flag = 0; i < str1.size(); i++)
	{
		if (str1[i] != '0') flag = 1;
		if (flag == 1)
			fout << str2[i];
		else fout << ' ';
	}
	fout << '\n';
	for (int i = 0, flag = 0; i < str2.size(); i++)
	{
		if (str2[i] != '0') flag = 1;
		if (flag == 1)
			fout << str2[i];
		else fout << ' ';
	}
	fout << '\n';
	for (int i = 0; i < str_sum.size(); i++)
		fout << '-';
	fout << '\n';
	for (int i = 0; i < str_sum.size(); i++)
		fout << str_sum[i];

	return 0;
}
