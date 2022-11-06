#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");
struct priziv
{
	int id;
	char all[50];
};
struct peoples
{
	char name[10];
	int id;
};
bool compar_strcmp(peoples * people_1, peoples * people_2)
{
	if (strcmp(people_1->name, people_2->name) <= 0)
		return true;
	return false;
}
bool compar_id(peoples * people_1, peoples * people_2)
{
	if (people_1->id < people_2->id)
		return true;
	return false;
}

bool compar(int a1, int a2)
{
	if (a1*a1 < a2*a2)
		return true;
	return false;
}
bool is_equal(int a1, int a2)
{
	if (a1*a1 == a2*a2) return true;
	return false;
}
bool compar_str(priziv * people_1, priziv * people_2)
{
	if (strcmp(people_1->all, people_2->all) < 0)
		return true;
	return false;
}
bool is_equal_str(priziv * people_1, priziv * people_2)
{
	if (strcmp(people_1->all, people_2->all) == 0)
		return true;
	return false;
}
bool compar_id_1(priziv * people_1, priziv * people_2)
{
	if (people_1->id < people_2->id)
		return true;
	return false;
}
int main()
{
	int arr[] = { 7, -10, -9, -8, 8, -7, -6, -5, 9 }, ar_del[] = { 2, 3, -2, 10, 11, -10}, arr_fill[10];
	sort(arr, arr + 8, compar);
	peoples * people[5];
	int n = 5;
	for (int i = 0; i < n; i++)
	{
		people[i] = (peoples*)malloc(sizeof(peoples));
		fin >> people[i]->name >> people[i]->id;
	}
	sort(people, people + 5, compar_id);

	sort(people, people + 5, compar_strcmp);

	sort(ar_del, ar_del + 6, compar);

	int * t = unique(ar_del, ar_del + 6, is_equal);
	for (int i = 0; i < t - ar_del; i++)
	{
		fout << ar_del[i];
	}
	fill(arr_fill, arr_fill + 10, 0);

	priziv * new_solder[1000];

	fin >> n;
	for (int i = 0; i < n; i++)
	{
		new_solder[i] = (priziv*)malloc(sizeof(priziv));
		fin >> new_solder[i]->id;
		//fin.getline(new_solder[i]->all);
		//getline(fin, new_solder[i]->all);
		fin.getline(new_solder[i]->all, 30);
	}
	sort(new_solder, new_solder + 12, compar_str);
	priziv ** t_p = unique(new_solder, new_solder + 12, is_equal_str);
	sort(new_solder, t_p, compar_id_1);

	return 0;
}