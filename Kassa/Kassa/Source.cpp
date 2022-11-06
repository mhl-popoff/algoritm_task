#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n, m, l[105], i, j, q, arr[30], schet[25];
	int min;
	bool flag = 0;
	fin >> n >> m;
	for (i = 0; i < m; i++)	{
		fin >> l[i];
	}
	for (j = 0; j < n; j++)	{
		arr[j] = 0;
		schet[j] = 0;
	}
	for (i = 0; i < m;)
	{
		if (flag == 0) min = l[i];
		for (j = 0; j < n; j++)	{
			if (flag == 0) {
				arr[j] += l[i];
				i++;
				schet[j]++;
			}
			else if (arr[j] == min)	{
				arr[j] += l[i];
				for (min = arr[j], q = 0; q < n; q++)	{
					if (min > arr[q])
					min = arr[q];
				}
				i++;
				schet[j]++;
				break;
			}
			if (arr[j] < min) {
				min = arr[j];
			}
			if (i >= m) break;
		}
		flag = 1;
	}
	for (j = 0; j < n; j++)	{
		fout << schet[j] << ' ';
	}

	return 0;
}