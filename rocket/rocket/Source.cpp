#include <fstream>
#include <math.h>
#include <algorithm>
#include <deque> //вектор через связанный список
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
	float x1, y1, x2, y2, i, temp = 1, hold;
	fin >> x1 >> y1 >> x2 >> y2;
	x2 = abs(x2 - x1);
	y2 = abs(y2 - y1);
	x1 = y1 = 0;
	if (x2 < y2) swap(x2, y2);
	for (i = 0; i <= x2; i++)
	{
		hold = (i * y2) / x2;
		if (abs(hold - round(hold)) < 0.001)
			temp += 3;
		else temp++;
	}

	fout << temp;
	return 0;
}