#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct mine {
	int number_field = -1;
	int x;
	int y;
};

void check(int k, int n, mine arr[], int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].number_field == -1)
		{
			if (x == arr[i].x)
			{
				if (arr[i].y == (y - 1) || arr[i].y == (y + 1))
				{
					arr[i].number_field = arr[k].number_field;
					check(i, n, arr, arr[i].x, arr[i].y);
				}
			}
			else if (y == arr[i].y)
			{
				if (arr[i].x == (x - 1) || arr[i].x == (x + 1))
				{
					arr[i].number_field = arr[k].number_field;
					check(i, n, arr, arr[i].x, arr[i].y);
				}
			}
		}
	}
}

int main()
{
	int m, n, mine_quantity,  region = 1;
	mine arr[100];
	fin >> m >> n >> mine_quantity;

	for (int hold = 0; hold < mine_quantity; hold++)
		fin >> arr[hold].x >> arr[hold].y;

	for (int hold = 0; hold < mine_quantity; hold++)
	{
		if (arr[hold].number_field == -1)
		{
			arr[hold].number_field = region;
			check(hold, mine_quantity, arr, arr[hold].x, arr[hold].y);
			region++;
		}
	}

	fout << region - 1;

	return 0;
}