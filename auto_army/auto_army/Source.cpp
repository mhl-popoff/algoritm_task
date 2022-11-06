#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct soldier
{
	float r;
	int brigade = -1;
};

void assign_neighbors(soldier * soldiers, int k, int n, float r)
{
	for (int i = 0; i < n; i++)
	{
		float distance = soldiers[i].r - soldiers[k].r;
		if (distance < 0) distance *= -1;
		if ((distance <= r) && (soldiers[i].brigade) == -1)
		{
			soldiers[i].brigade = soldiers[k].brigade;
			assign_neighbors(soldiers, i, n, r);
		}
	}
}

int main()
{
	int n;
	float r;
	fin >> n >> r;
	soldier soldiers[1000];
	for (int i = 0; i < n; i++)	
		fin >> soldiers[i].r;
	int brigade_num = 1;
	for (int i = 0; i < n; i++)
	{
		if (soldiers[i].brigade == -1)
		{
			soldiers[i].brigade = brigade_num;
			assign_neighbors(soldiers, i, n, r);
			brigade_num++;
		}
	}

	fout << brigade_num - 1;
	return 0;
}