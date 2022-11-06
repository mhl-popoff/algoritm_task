#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
	int arr[10000], i = 0;
	fin >> arr[i];
	while (arr[i] != 0)
	{
		i++;
		fin >> arr[i];
	}
	return 0;
}