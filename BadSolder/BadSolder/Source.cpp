#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct soldier
{
	int number;
	soldier * ptr = NULL;
};

int main()
{
	int i, j, m, n, k;
	soldier * s = (soldier*)malloc(sizeof(soldier));
	soldier * first = (soldier*)malloc(sizeof(soldier));
	fin >> n >> m >> k;
	for (i = 0; i < n; i++)	{
		s->ptr = (soldier*)malloc(sizeof(soldier));
		s->number = i + 1;
		if (i == 0) first = s;
		if (i != n - 1) s = s->ptr;
		else if (i == n - 1) s->ptr = first;
	}
	for (s = first; m > 1; m--)	{
		s = s->ptr;
	}
	
	for (; n >= 0; n--)	{
		j = 1;
		for (; j < k - 1; j++)		{
			s = s->ptr;
		}
		s->ptr = s->ptr->ptr;
		if (j == k - 1) s = s->ptr;
	}
	fout << s->number;
	return 0;
}