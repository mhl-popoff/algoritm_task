#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
void move_town(int n, char a, char c, char b)
{
	if (n == 0)	return;
	move_town(n - 1, a, b, c);
	fout << n << " => " << c << '\n';
	move_town(n - 1, b, c, a);
	return;
}

int main()
{
	int n;
	fin >> n;
	move_town(n, 'A', 'C', 'B');
	return 0;
}