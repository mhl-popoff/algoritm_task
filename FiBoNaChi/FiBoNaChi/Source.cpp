#include <iostream>

int fibo(int n)
{
	if (n == 1)	return 0;
	if (n == 2) return 1;
	int sum = fibo(n - 1) + fibo(n - 2);
	return sum;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << fibo(n);
	return 0;
}