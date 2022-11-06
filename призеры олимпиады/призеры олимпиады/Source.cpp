#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");

int main()
{
	int n, temp = 1;
	fin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		fin >> vec[i];
	sort(vec.begin(), vec.end());
	if (n <= 3) {
		fout << n;
		return 0;
	}
	for (int i = 0; i < 2; i++)
	{
		if (vec[n - 1] == vec[n - 2]) i--;
		temp++;
		n--;
	}
	fout << temp;
	return 0;
}