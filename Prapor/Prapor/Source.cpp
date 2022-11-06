#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int my_factorial(int n)
{
	if (n == 1) return 1;
	n = n * my_factorial(n - 1);
	return n;
}
int translatio_time(vector<int>docs, float k)
{
	int time = 0;
	for (int i = 0; i < docs.size(); i++)
	{
		if (k >= docs[i])
		{
			time += docs[i];
			k += docs[i] * 0.1;
		}
		else
		{
			time += (2 * docs[i]);
			k += docs[i] * 0.1;
		}
	}

	return time;
}

int main()
{
	//fout << my_factorial(5) << "\n";
	int n, k, min_time, hold;
	bool flag = 0;
	fin >> n >> k;
	vector<int>documents(n);
	vector<int>min_vec(n);
	for (int i = 0; i < n; i++)
		fin >> documents[i];
	n = my_factorial(n);
	min_vec = documents;
	min_time = min_time = translatio_time(documents, k);
	for (int i = 0; i < n; i++)
	{
		next_permutation(documents.begin(), documents.end());
		hold = translatio_time(documents, k);
		if (min_time > hold)
		{
			min_vec = documents;
			min_time = hold;
		}
	}

	fout << min_time << '\n';
	for (int i = 0; i < min_vec.size(); i++)
		fout << min_vec[i] << ' ';
	return 0;
}