#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");
int main()
{
	int n, k;
	fin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		fin >> vec[i];
	fin >> k;
	sort(vec.begin(), vec.begin() + k);
	sort(vec.begin() + k, vec.end());

	return 0;
}