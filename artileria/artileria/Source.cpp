#include <fstream>
#include <math.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct tank{
	int number;
	float x;
	float y;
	bool life = 1;
};

struct shot {
	int number;
	float x;
	float y;
	float r;
};

int main()
{
	int i, j, n, m, hold, temp = 0;
	fin >> n >> m;
	
	tank car[100];
	shot weapon[100];

	for (i = 0; i < n; i++)
	{
		car[i].number = i + 1;
		fin >> car[i].x >> car[i].y;
	}

	for (j = 0; j < m; j++)
	{
		fin >> weapon[j].number >> weapon[j].x >> weapon[j].y >> weapon[j].r;
	}

	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{	
			hold = weapon[j].number;
			if ((sqrt((car[i].x - weapon[j].x) * (car[i].x - weapon[j].x) + (car[i].y - weapon[j].y) * (car[i].y - weapon[j].y)) <= weapon[j].r) && car[hold].life == 1)
			{
				car[i].life = 0;
				temp++;
			}
		}
	}
	
	fout << temp;
	
	return 0;
}