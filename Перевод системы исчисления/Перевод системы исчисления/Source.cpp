#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");
int dig_to_chat(int dig) {
	if (dig <= 9)
		return (char)(dig + '0');
	return (char)(dig + 'A' - 10);
}
int main()
{
	int sist_isch, dig, i = 0, n;
	char str[10];
	fin >> sist_isch >> dig;
	while (dig > sist_isch)
	{
		str[i] = dig_to_chat(dig % sist_isch);
		i++;
		dig /= sist_isch;
	}
	str[i] = dig_to_chat(dig % sist_isch);
	str[i + 1] = 0;
	n = strlen(str);
	for (; n > 0; n--)
		fout << str[n - 1];
	return 0;
}
// из любой в десятичную
//int char_to_int(char c) {
//	if (c <= '9' && c >= '0')
//		return (int)(c - '0');
//	return (int)(c - 'A' + 10);
//}
//int stepen(int a, int i) {
//	if (i == 0) return 1;
//	a = a * stepen(a, i - 1);
//	return a;
//}
//int main() {
//	char str[10];
//	int sist_isch, sum = 0;
//	fin >> sist_isch >> str;
//	for (int n = strlen(str), i = 1; n > 0; n--, i++)
//		sum += char_to_int(str[i - 1]) * stepen(sist_isch, n - 1);
//	fout << sum;
//	return 0;
//}