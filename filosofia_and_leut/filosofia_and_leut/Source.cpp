#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
struct soldier
{
	char name[10];
	int id;
	float height;
};
bool sort_id(soldier * a1, soldier * a2)
{
	if (a1->id < a2->id)
		return true;
	return false;
}
bool sort_name(soldier * a1, soldier * a2)
{
	if (strcmp(a1->name, a2->name) < 0)
		return true;
	return false;
}
bool sort_height(soldier * a1, soldier * a2)
{
	if (a1->height < a2->height)
		return true;
	return false;
}
int main()
{
	int n, i, j;
	vector<soldier*> soldiers;
	vector<soldier*> ideal;
	soldier * buf;
	vector<soldier*>::iterator it;
	fin >> n;
	for (i = 0; i < n; i++)	{
		buf = new soldier;
		fin >> buf->name >> buf->id >> buf->height;
		soldiers.push_back(buf);
	}
	sort(soldiers.begin(), soldiers.end(), sort_id);
	it = soldiers.begin();
	if (n % 2 == 0)
	{
		ideal.push_back(soldiers[n / 2]);
		ideal.push_back(soldiers[n / 2 - 1]);
		soldiers.erase(soldiers.begin() + (n / 2 - 1), soldiers.begin() + (n / 2 + 1));
		n -= 2;
	}
	else 
	{
		ideal.push_back(soldiers[n / 2]);
		soldiers.erase(soldiers.begin() + (n / 2 - 1));
		n -= 1;
	}
	sort(soldiers.begin(), soldiers.end(), sort_name);
	ideal.push_back(soldiers[n / 2]);
	ideal.push_back(soldiers[n / 2 - 1]);
	soldiers.erase(soldiers.begin() + (n / 2 - 1), soldiers.begin() + (n / 2 + 1));
	sort(soldiers.begin(), soldiers.end(), sort_height);
	ideal.push_back(soldiers[n / 2]);
	ideal.push_back(soldiers[n / 2 - 1]);
	sort(ideal.begin(), ideal.end(), sort_name);

	for (i = 0; i < 6; i++)
		fout << ideal[i]->name << '\n';

	return 0;
}