#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int ** minor(int ** matrix, int n, int k)
{
	int ** matrix_minor = (int**)malloc(sizeof(int*) * (n - 1));
	for (int i = 0; i < n - 1; i++)
		matrix_minor[i] = (int*)malloc(sizeof(int) * (n - 1));
	int num_str = 0;
	for (int i = 0; i < n; i++)	{
		if (i != k)	{
			for (int j = 0; j < n - 1; j++)	{
				matrix_minor[num_str][j] = matrix[i][j + 1];
			}
			num_str++;
		}
	}
	return matrix_minor;
}

int determinant(int** matrix,int n) 
{
	if (n == 1) return matrix[0][0];
	int determ = 0;
	for (int koef = 1, i = 0; i < n; i++, koef *= (-1))	{
		determ += koef * (matrix[i][0] * determinant(minor(matrix, n, i), n - 1));
	}
	return determ;
}

int main()
{
	int n;
	fin >> n;
	int ** matrix = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++)	{
			fin >> matrix[i][j];
		}
	}
	fout << determinant(matrix, n);
	return 0;
}