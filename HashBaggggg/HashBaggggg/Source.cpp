#include <fstream>
#include <stdio.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool polinominal(int arr[], int x, int m, int L, int v)
{
	bool flag = 0;
	int i, hold;
	long long sum = 0;
	int koeff = 1;
	for (i = 0; i < L; i++)
	{
		sum += arr[i] * koeff;// *pow(x, i);
		koeff *= x;
	}

	if (sum % m == v)
		flag = 1;

	return flag;
}

int main()
{
	//printf("%02d", 1);
	//system("pause");
	int i, j, x, m, L, v, str_int[100], mas_perehod[100];
	bool compled = 0;

	fin >> x >> m >> L >> v;

	int arr[100];
	for (int i = 0; i < 100; i++)
		arr[i] = 0;
	char buf[11];
	int start = 1000000000;
	do{
		sprintf(buf, "%d", start);
		for (int i = 0; i < 10; i++) {
			arr[i] = (int)(buf[i] - '0');
		}
		start++;
	} while (!polinominal(arr, x, m, L, v));

	for (i = 0; i < L; i++)
	{
		fout << arr[i];
	}

	return 0;
}