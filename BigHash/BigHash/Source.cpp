#include <fstream>

using namespace std;

int hold(int arr)
{
	char str[20];

	sprintf(str, "%d", arr);
	int dig;
	int sum = arr;
	char * ptr = str;
	while (*ptr != 0)
	{
		dig = (int)(*ptr - '0');
		if (dig % 2 == 0)
			sum += dig + 1 + dig * dig;
		else sum += dig + 1 + dig * dig * dig;
		ptr++;
	}
	return sum;
}

int main()
{
	int i, j = 0, n, arr[10000], temp;
	FILE * fp = fopen("input.txt", "r");
	FILE * fp_2 = fopen("output.txt", "w");

	char str[20], str_all[100000];
	char * ptr;


	int sum_chet = 0, sum_nechet = 0, sum_all = 0;
	bool flag_chet = 0, flag_nechet = 0;

	fscanf(fp, "%d", &n);

	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &arr[i]);
		arr[i] = hold(arr[i]);
		sprintf(str, "%d", arr[i]);

		ptr = str;
		while (*ptr != 0)
		{
			temp = (int)(*ptr - '0');
			if (temp % 2 == 0)
			{
				flag_chet = 1;
				sum_chet += temp;
			}
			else
			{
				flag_nechet = 1;
				sum_nechet += temp;
			}
			str_all[j] = temp + '0';
			str_all[j + 1] = 0;
			j++;
			ptr++;
		}
	}
	sscanf(str_all, "%d", &sum_all);
	if (flag_chet == 0)
		sum_chet = 1;
	if (flag_nechet == 0)
		sum_nechet = 1;

	sum_all = sum_all / (sum_chet * sum_nechet);
	fprintf(fp_2, "%d", sum_all);
	return 0;
}