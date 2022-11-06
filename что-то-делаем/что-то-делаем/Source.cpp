#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
bool check(vector<int>arr_all)
{
	bool flag = 0;
	for (int i = 0; i < arr_all.size(); i += 2)
	{
		if (arr_all[i] != arr_all[i + 1]) flag = 1;
	}
	return flag;
}
int main()
{
	vector<int>arr_all;
	bool flag = 0;
	int n;
	fin >> n;
	vector<int>arr_1(n);
	vector<int>arr_2(n);
	for (int i = 0; i < n; i++)
	{
		fin >> arr_1[i];
		arr_all.push_back(arr_1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		fin >> arr_2[i];
		arr_all.push_back(arr_2[i]);
	}
	sort(arr_all.begin(), arr_all.end());
	flag = check(arr_all);
	if (flag == 0)
	{
		unique(arr_all.begin(), arr_all.end());
		for (int i = 0; i < n; i++)
			fout << arr_all[i] << ' ';
		fout << '\n';
		for (int i = 0; i < n; i++)
			fout << arr_all[i] << ' ';
	}
	else
	{
		for (int i = 0; i < arr_1.size(); i++)
			fout << arr_1[i] << ' ';
		fout << '\n';
		for (int i = 0; i < arr_1.size(); i++)
			fout << arr_2[i] << ' ';
	}
	return 0;
}