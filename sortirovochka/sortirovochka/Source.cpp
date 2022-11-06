#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct student
{
	char name[20];
	float rate;
};

int main()
{
	FILE * fp_in = fopen("in.txt", "r");
	FILE * fp_out = fopen("out.txt", "w");

	int i, j, n;

	fscanf(fp_in, "%d", &n);

	student * student_arr[100];
	for (i = 0; i < n; i++)
	{
		student_arr[i] = (student*)malloc(sizeof(student));
		fscanf(fp_in, "%s%f", student_arr[i]->name, &student_arr[i]->rate);
	}


	student * hold;
	//student_arr[0] = student_arr[1];
	//student_arr[1] = hold;

	for (i = 0; i < n; i++)
	{
		hold = student_arr[i];
		for (j = i + 1; j < n; j++)
		{
			if (student_arr[i]->rate >= student_arr[j]->rate)
			{
				student_arr[i] = student_arr[j];
				student_arr[j] = hold;
			}
		}
		fprintf(fp_out, "%s %.1f\n", student_arr[i]->name, student_arr[i]->rate);
	}



	return 0;
}