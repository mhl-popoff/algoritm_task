#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");


long double cube(long double a, long double b, long double c, long double x)
{
	long double ret;
	ret = x*x*x + a*x*x + b * x + c;
	return ret;
}

int main()
{
	long double left_x, right_x, mid, y, a, b, c;
	left_x = -10.0;
	right_x = 10.0;
	fin >> a >> b >> c;
	mid = right_x;
	while (abs(right_x - left_x) > 0.0001)
	{
		if (cube(a, b, c, left_x) * cube(a, b, c, mid) < 0.0)
			right_x = mid;
		else 
			left_x = mid;
		mid = (left_x + right_x) / 2.0;
	}

	y = mid;

	fout << fixed << showpoint;
	fout << setprecision(2);
	fout << y;
	return 0;
}
