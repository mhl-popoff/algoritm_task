//#include <fstream>
//#include <iostream>
//using namespace std;
//ifstream fin("input.txt");
//ofstream fout("output.txt");
//int main()
//{
//	int n, m, k, hold;
//	fin >> n >> m;
//	int * arr = (int*)malloc(sizeof(int) * m);
//	k = n;
//	for (int i = 0; i < n && i < m; i++)
//		arr[i] = 0;
//	for (int i = 0; i < m; i++)	{
//		fin >> hold;
//		if (arr[hold - 1] == 0) k--;
//		arr[hold - 1]++;
//		if (k == 0)	{
//			for (int j = 0; j < n; j++)	{
//				arr[j]--;
//				if (arr[j] == 0) k++;
//			}
//			fout << 1;
//		}
//		else fout << 0;
//	}
//	return 0;
//}
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m, k, arr[100000];
	cin >> n >> m;
	k = n;
	std::vector<int> a(m);
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		if (arr[a[i] - 1] == 0) k--;
		arr[a[i] - 1]++;
		if (k == 0) {
			for (int j = 0; j < n; j++) {
				arr[j]--;
				if (arr[j] == 0) k++;
			}
			cout << 1;
		}
		else cout << 0;
	}
	return 0;
}
