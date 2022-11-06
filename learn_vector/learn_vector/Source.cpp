#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");

//int main()
//{
//	vector<int>vec;
//	vec.push_back(105);
//	vec.push_back(11);
//	for (int i = 0; i < vec.size(); i++)
//		cout << vec[i] << " ";
//	vector<int>::iterator it;
//	it = vec.begin();
////	it = vec.end();
//	vec.erase(vec.begin());
//	vec.push_back(2);
//	vec.push_back(3);
//	vec.push_back(4);
//	vec.push_back(5);
//	vec.push_back(6);
//	it = vec.begin();
//	vec.erase(vec.begin() + 1, vec.begin() + 2);
//
//	while (it != vec.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	system("pause");
//	return 0;
//}
struct people
{
	int id;
	char name[10];
};
bool sort_id(people * a1, people * a2)
{
	if (a1->id < a2->id)
		return true;
	return false;
}
bool sort_name(people * a1, people * a2)
{
	if (strcmp(a1->name,a2->name) < 0)
		return true;
	return false;
}
int main()
{
	int hold = 0;
	vector<people*>vec;
	people * buf;
	vector<people*>::iterator start;
	vector<people*>::iterator finish;
	while (true)
	{	
		buf = (people*)malloc(sizeof(people));
		fin >> buf->id;
		if (buf->id == 0) break;
		fin >> buf->name;
		vec.push_back(buf);
		hold++;
	}
	start = vec.begin();
	finish = vec.end();
	sort(start, finish, sort_id);
	int i = 0;
	while (start != vec.end())
	{
		fout << vec[i]->id << " " << vec[i]->name << "\n";
		i++;
		start++;
	}
	start = vec.begin();
	i = 0;
	sort(start, finish, sort_name);
	while (start != vec.end())
	{
		fout << vec[i]->id << " " << vec[i]->name << "\n";
		i++;
		start++;
	}
	return 0;
}