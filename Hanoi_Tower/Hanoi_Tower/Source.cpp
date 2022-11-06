#include <iostream>
void disk(int n, char s, char h, char d)
{
	if (n == 0) return;
	disk(n - 1, s, d, h);
	std :: cout << n << " => " << d << std :: endl;
	disk(n - 1, h, s, d);
	return;
}
int main()
{
	int n;
	std :: cin >> n;
	disk(n, 'A', 'B', 'C');
	return 0;
}