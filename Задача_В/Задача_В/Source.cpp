#include <iostream>
using namespace std;

long long find_n_1(long long n)
{
	n = (((n - 1) * (n - 1) - (n - 1)) / 2) + (n - 1) + 1;
	return n;
}
int main()
{
	long long i, a, b, number_start;
	int k, j;
	cin >> a >> b >> k;

	for (i = b - a; i >= 0; i--)
	{
		number_start = find_n_1(a);
		for (j = 1; j <= k; j++)
		{
			cout << number_start << ' ';
			number_start++;
			if (a == j) break;
		}
		a++;
		cout << '\n';
	}
	return 0;
}