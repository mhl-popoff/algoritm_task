#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int mn = 99999, x2, y2, z2;
char mas[52][52][52] = { ',', };
void fun(int x, int y, int z, int sum, int k)
{
	if (x == x2&&y == y2&&z == z2)
	{
		mn = min(mn, sum);
		return;
	}
	if (k != 4)
		if (mas[x + 1][y][z] == '.')
		{
			fun(x + 1, y, z, sum + 1, 1);
		}
	if (k != 1)
		if (mas[x - 1][y][z] == '.')
		{
			fun(x - 1, y, z, sum + 1, 4);
		}
	if (k != 5)
		if (mas[x][y + 1][z] == '.')
		{
			fun(x, y + 1, z, sum + 1, 2);
		}
	if (k != 2)
		if (mas[x][y - 1][z] == '.')
		{
			fun(x, y - 1, z, sum + 1, 5);
		}
	if (k != 6)
		if (mas[x][y][z + 1] == '.')
		{
			fun(x, y, z + 1, sum + 1, 3);
		}
	if (k != 3)
		if (mas[x][y][z - 1] == '.')
		{
			fun(x, y, z - 1, sum + 1, 6);
		}
}
int main()
{
	int n, m, h, x1, y1, z1;
	cin >> n >> m >> h >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	for (int k = 1; k <= h; k++)
		for (int j = 1; j <= m; j++)
			for (int i = 1; i <= n; i++)
				cin >> mas[i][j][k];
	fun(x1, y1, z1, 0, 0);
	cout << mn;
}