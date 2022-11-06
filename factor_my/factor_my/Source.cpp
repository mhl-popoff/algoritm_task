#include <iostream>

int my_factorial(int n)
{
	if (n == 1) return n;
	n = n * my_factorial(n - 1);
	return n;
}

int main()
{
	int n;
	std :: cin >> n;
	n = my_factorial(n);
	std :: cout << '\n' << n;
	system("pause");
}
//
//void F(int n)
//{
//	if (n > 3) {
//		F(n / 2);
//		F(n - 2);
//	}
//	std::cout << n;
//}
//
//int main()
//{
//	int n = 9;
//	F(n);
//	system("pause");
//	return 0;
//}