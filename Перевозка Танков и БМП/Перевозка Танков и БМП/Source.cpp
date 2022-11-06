#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
	long long int n, m, hold, temp = 0;
	fin >> n >> m;
	if (n >= 3)	{
		hold = n / 3;
		temp += hold;
		m -= hold;
		n %= 3;
	}
	if (n == 2)	{
		n -= 2;
		m -= 4;
		temp++;
	}
	if (n == 1)	{
		n--;
		m -= 8;
		temp++;
	}
	if (m > 0)	{
		if (m % 12 == 0)
			temp += m / 12;
		else temp += m / 12 + 1;
	}
	/*while (n > 0 || m > 0)
	{
		if (n >= 3)
		{
			n -= 3;
			m--;
		}
		else if (n == 2)
		{
			n -= 2;
			m -= 4;
		}
		else if (n == 1)
		{
			n--;
			m -= 8;
		}
		else if (m >= n)
			m -= 12;

		temp++;
	}*/
	fout << temp;
	return 0;
}