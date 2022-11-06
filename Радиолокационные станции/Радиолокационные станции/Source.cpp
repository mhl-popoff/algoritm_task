#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");
struct RLC {
	float x;
	float y;
	float r;
};
struct BLA {
	float x;
	float y;
};
int main()
{
	int i, j, n, m;
	fin >> n >> m;
	RLC RLC_s[31];
	BLA BLA_s[31];
	for (i = 0; i < n; i++)
		fin >> RLC_s[i].x >> RLC_s[i].y >> RLC_s[i].r;
	for (i = 0; i < m; i++)
		fin >> BLA_s[i].x >> BLA_s[i].y;
	for (j = 0; j < m; j++)	{
		fout << j + 1;
		for (i = 0; i < n; i++)	{
			if (RLC_s[i].r * RLC_s[i].r >= (RLC_s[i].x - BLA_s[j].x) * (RLC_s[i].x - BLA_s[j].x) + (RLC_s[i].y - BLA_s[j].y) * (RLC_s[i].y - BLA_s[j].y))
				fout << ' ' << i + 1;
		}
		fout << '\n';
	}
	return 0;
}