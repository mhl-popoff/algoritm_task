#include <iostream>

using namespace std;

int main()
{
	int i, j, n, m;
	cin >> n >> m;

	if (n == m) cout << n + m;
	else if (n > m)
	{
		if ((n + m) % 2 == 0)
			cout << (m + m);
		else cout << (m + m + 1);
	}
	else if (m > n)
	{
		if ((n + m) % 2 == 0)
			cout << (n + n);
		else cout << (n + n + 1);
	}

	return 0;
}