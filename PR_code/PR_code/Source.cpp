#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
	int n, sum = 0;
	fin >> n;
	vector<int> arr_min(n);
	for (int i = 0; i < n; i++)
		fin >> arr_min[i];
	sort(arr_min.begin(), arr_min.end());
	for (int i = 0; i <= n / 2; i++)
		sum += arr_min[n - i - 1];
	fout << sum;
	return 0;
}