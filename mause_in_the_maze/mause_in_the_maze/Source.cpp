#include <fstream>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int main()
{
	int n, m, i, j, i_b, j_b, arr[100][100], hold = 0;
	char maze[100][100];
	bool flag = 0;
	fin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			fin >> maze[i][j];
			arr[i][j] = -1;
			if (maze[i][j] == 'f')
				arr[i][j] = 0;
			if (maze[i][j] == 'b')
			{
				i_b = i;
				j_b = j;
			}			
		}
	}
	while (arr[i_b][j_b] < 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (arr[i][j] == hold)
				{
					if (arr[i + 1][j] == -1 && (maze[i + 1][j] == '.' || maze[i + 1][j] == 'b'))
					{
						arr[i + 1][j] = hold + 1;
					}
					if (arr[i - 1][j] == -1 && (maze[i - 1][j] == '.' || maze[i - 1][j] == 'b'))
					{
						arr[i - 1][j] = hold + 1;
					}
					if (arr[i][j - 1] == -1 && (maze[i][j - 1] == '.' || maze[i][j - 1] == 'b'))
					{
						arr[i][j - 1] = hold + 1;
					}
					if (arr[i][j + 1] == -1 && (maze[i][j + 1] == '.' || maze[i][j + 1] == 'b'))
					{
						arr[i][j + 1] = hold + 1;
					}
				}
			}
		}
		hold++;
	}
	fout << hold << '\n';
	while (hold >= 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (arr[i][j] == hold && maze[i][j] == 'b')
				{
					if ((maze[i + 1][j] == '.' || maze[i + 1][j] == 'f') && arr[i + 1][j] == hold - 1)
					{
						fout << 'S';
						maze[i + 1][j] = 'b';
						flag = 1;
						break;
					}
					if ((maze[i - 1][j] == '.' || maze[i - 1][j] == 'f') && arr[i - 1][j] == hold - 1)
					{
						fout << 'N';
						maze[i - 1][j] = 'b';
						flag = 1;
						break;
					}
					if ((maze[i][j - 1] == '.' || maze[i][j - 1] == 'f') && arr[i][j - 1] == hold - 1)
					{
						fout << 'W';
						maze[i][j - 1] = 'b';
						flag = 1;
						break;
					}
					if ((maze[i][j + 1] == '.' || maze[i][j + 1] == 'f') && arr[i][j + 1] == hold - 1)
					{
						fout << 'E';
						maze[i][j + 1] = 'b';
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1)
			{
				flag = 0;
				break;
			}
		}
		hold--;
	}
	return 0;
}