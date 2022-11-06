#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");
int main()
{
	int n;
	map <string,int> str;
	string str_hold;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> str_hold;
		if (str[str_hold] == 0)	fout << "OK\n";
		else fout << str_hold << str[str_hold] << '\n';
		str[str_hold]++;
	}
	return 0;
}