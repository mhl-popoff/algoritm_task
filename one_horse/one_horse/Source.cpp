#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
	int i, j, n, x1, y1, x2, y2, arr[21][21];
	fin >> n >> x1 >> y1 >> x2 >> y2;
	for (i = 0; i < n; i++)
		fill(arr[i], arr[n], -1);
	arr[y1 - 1][x1 - 1] = 0;
	for (int step = 0; arr[y2 - 1][x2 - 1] == -1; step++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)	{
				if (arr[i][j] == step) {
					if (i - 1 >= 0 && j - 2 >= 0)
						arr[i - 1][j - 2] = step + 1;
					if (i - 1 >= 0 && j + 2 < n)
						arr[i - 1][j + 2] = step + 1;
					if (i + 1 < n && j - 2 >= 0)
						arr[i + 1][j - 2] = step + 1;
					if (i + 1 < n && j + 2 < n)
						arr[i + 1][j + 2] = step + 1;
					if (i - 2 >= 0 && j - 1 >= 0)
						arr[i - 2][j - 1] = step + 1;
					if (i - 2 >= 0 && j + 1 < n)
						arr[i - 2][j + 1] = step + 1;
					if (i + 2 < n && j - 1 >= 0)
						arr[i + 2][j - 1] = step + 1;
					if (i + 2 < n && j + 1 < n)
						arr[i + 2][j + 1] = step + 1;
				}
			}
		}
	}

	fout << arr[y2 - 1][x2 - 1];
	return 0;
}