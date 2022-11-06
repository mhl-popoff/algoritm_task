#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");
bool my_sort(int a1, int a2)
{
	if (a1 > a2)
		return true;
	return false;
}
int main()
{
	int n, arr[1000][2];
	fin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i][0] >> arr[i][1];
		if (arr[i][0] > arr[i][1]) vec.push_back(arr[i][0]);
		else vec.push_back(arr[i][1]);
	}
	sort(vec.begin(), vec.end(), my_sort);
	
	for (int i = 0; i < n; i++)
		fout << vec[i] << ' ';
	return 0;
}