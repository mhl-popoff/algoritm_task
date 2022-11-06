#include <fstream>
#include <algorithm>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int factorial(int n)
{
	if (n == 1) return n;
	n = n * factorial(n - 1);
	return n;
}

int main()
{
	char n[10];
	fin >> n;
	int start_len = strlen(n);
	int len = factorial(strlen(n));
	for (int i = 0; i < len; i++)
	{
		fout << n << '\n';
		std::next_permutation(n, n + start_len);
	}
	return 0;
}