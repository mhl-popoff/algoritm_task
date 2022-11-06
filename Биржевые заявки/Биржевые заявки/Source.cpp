#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");
struct exchange_my
{
	char d;
	int p;
	int q;
};
bool my_sort_plus(exchange_my a1, exchange_my a2)
{
	if (a1.p > a2.p)
		return true;
	return false;
}
bool my_sort_minus(exchange_my a1, exchange_my a2)
{
	if (a1.p < a2.p)
		return true;
	return false;
}
int main()
{
	int n, s, index = 0;
	fin >> n >> s;
	vector<exchange_my> buy, sale;
	exchange_my hold;
	for (int i = 0; i < n; i++)
	{
		fin >> hold.d >> hold.p >> hold.q;
		if (hold.d == 'B')
			buy.push_back(hold);
		else sale.push_back(hold);
	}
	for (int i = 0; i < buy.size(); i++)
	{
		for (int j = i + 1; j < buy.size(); j++)
		{
			if (buy[i].p == buy[j].p)
			{
				buy[i].q += buy[j].q;
				buy.erase(buy.begin() + j);
				j--;
			}
		}
	}
	for (int i = 0; i < sale.size(); i++)
	{
		for (int j = i + 1; j < sale.size(); j++)
		{
			if (sale[i].p == sale[j].p)
			{
				sale[i].q += sale[j].q;
				sale.erase(sale.begin() + j);
				j--;
			}
		}
	}
	sort(buy.begin(), buy.end(), my_sort_plus);
	sort(sale.begin(), sale.end(), my_sort_minus);
	if (sale.size() > s - 1) sale.erase(sale.begin() + s, sale.end());
	sort(sale.begin(), sale.end(), my_sort_plus);
	for (int i = 0; i < s && sale.size() > 0 && i < sale.size(); i++)
		fout << sale[i].d << ' ' << sale[i].p << ' ' << sale[i].q << '\n';
	for (int i = 0; i < s && buy.size() > 0 && i < buy.size(); i++)
		fout << buy[i].d << ' ' << buy[i].p << ' ' << buy[i].q << '\n';

	return 0;
}