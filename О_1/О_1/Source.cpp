#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
//int main()
//{
//	int i, j, n, m, len_lolypops = 0, hold = 0, max_lolypops = 0;
//	char str[305][305];
//	bool flag = 0;
//	fin >> n >> m;
//	for (i = 0; i < n; i++)
//		for (j = 0; j < m; j++)
//			fin >> str[i][j];
//	for (i = 0; i < n; i++)
//	{
//		if (str[i][0] == '.' && flag == 0)
//		{
//			len_lolypops++;
//			for (j = 0; j < m; j++)
//			{
//
//			}
//		}
//		else if (str[i][0] == '#' && flag == 0 && len_lolypops > 0)
//			flag = 1;
//		else if (str[i][0] == '.' && flag == 1)
//		{
//			hold++;
//			if (len_lolypops < hold)
//			{
//				flag = 0;
//				len_lolypops++;
//			}
//		}
//	}
//
//	fout << max_lolypops;
//	return 0;
//}
//void check(int n)
//{
//	bool flag = 0;
//	int x = 2, y = 2, P = 0, best_x = 0, best_y = 0;
//	if (n * n + 1 < x * y) {
//		fout << -1 << '\n';
//		return;
//	}
//	while (x <= (n * n + 1) / 2) {
//		if (x < n) y = n;
//		else y = x + 1;
//		while (y <= (n * n + 1) / 2) {
//			if (x * y == n * n + 1)
//			{
//				if (P < (x + y) * 2)
//				{
//					best_x = x;
//					best_y = y;
//					P = (x + y) * 2;
//					break;
//				}
//				else flag = 1;
//			}
//			y++;
//		}
//		if (flag == 1) break;
//		x++;
//	}
//	if (best_x == 0)
//		fout << -1 << '\n';
//	else fout << best_x << ' ' << best_y << '\n';
//}
//int main()
//{
//	int q, n[100000], x, y;
//	fin >> q;
//	for (int i = 0; i < q; i++)
//	{
//		fin >> n[i];
//		check(n[i]);
//	}
//
//	return 0;
//}
struct drone
{
	int x;
	int y;
	bool flag = 0;
};
int main()
{
	int i, n, quantity_flag = 0;
	drone drones[10000];
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> drones[i].x >> drones[i].y;
		if (drones[i].x * drones[i].x == drones[i].y * drones[i].y || drones[i].x == 0 || drones[i].y == 0)
			drones[i].flag = 1;
		quantity_flag++;
	}
	if (quantity_flag > 2) fout << -1;
	else
	{
		for (int i = 0; i < n; i++) {
			if (drones[i].flag == 1)
			{
				fout << i + 1 << ' ';
				for (int j = 0; j < n; j++) {
					drones[j].x = 0;
				}
			}

		}
	}
	return 0;
}