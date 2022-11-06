#include <stdio.h>
#include <iostream>

using namespace std;

int hold(int arr)
{
	char str[20];

	sprintf(str, "%d", arr);
	int dig;
	int summ = arr;
	char * ptr = str;
	while (*ptr != 0) {
		dig = (int)(*ptr - '0');
		summ += dig + dig*dig;
		ptr++;
	}


	return summ;
}

int main()
{
	FILE * fp = fopen("in.txt", "r");
	FILE * fp_2 = fopen("out.txt", "w");
	char str[20];
	int i, n, arr[20], sum = 0;

	fscanf(fp, "%d", &n);

	for (i = 0; i < n; i++)
	{
		fscanf(fp,"%d", &arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = hold(arr[i]);
		sum += arr[i];
	}
	sprintf(str, "%d", sum);
	char * p = str;
	if (strlen(str) >= 4)
		char * p = str + strlen(str) - 4;

	fprintf(fp_2, "%s", p);

	return 0;
}