#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
struct angar
{
	long long time;
	bool fire = 0;
};
int minimal(angar arr[][21], int m, int n)
{
	int min = 0;
	bool flag = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j].fire == 1)
			{
				if (flag == 0 && arr[i][j].time > 0)
				{
					min = arr[i][j].time;
					flag = 1;
				}
				else if (min > arr[i][j].time && arr[i][j].time > 0) min = arr[i][j].time;
			}
	return min;
}
long long fire_fire(angar arr[][21], int m, int n, long long min)
{
	long long time = 0;
	bool flag = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j].fire == 1 && arr[i][j].time > 0)
			{
				arr[i][j].time-= min;
				if (arr[i][j].time == 0) arr[i][j].time = -1;
				flag = 1;
			}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j].time == -1)
			{
				if (arr[i + 1][j].time > 0) arr[i + 1][j].fire = 1;
				if (arr[i - 1][j].time > 0) arr[i - 1][j].fire = 1;
				if (arr[i][j + 1].time > 0) arr[i][j + 1].fire = 1;
				if (arr[i][j - 1].time > 0) arr[i][j - 1].fire = 1;
			}
	if (flag == 1) time+=min;
	return time;
}
int main()
{
	long long m, n, a, b, i, j, time = 0, hold, min;
	fin >> m >> n >> a >> b;
	angar arr[21][21];
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			fin >> arr[i][j].time;
	i = a - 1;
	j = b - 1;
	arr[i][j].fire = 1;
	while (1)
	{
		min = minimal(arr, m, n);
		hold = fire_fire(arr, m, n, min);
		if (hold == 0) break;
		time += hold;
	}
	fout << time;
	return 0;
}