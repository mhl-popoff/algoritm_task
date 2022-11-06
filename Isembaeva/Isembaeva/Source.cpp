#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("Text.txt");
ofstream fout("Text1.txt");
int main()
{
	int n, count = 0;
	bool flag = 0;
	string str;
	fin >> n;
	vector <vector<string>> olimp(n);
	map <string, int> people;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
		{
			fin >> str;
			olimp[i].push_back(str);
			people[str] = 101;
		}
	people["Isenbaev"] = 0;
	while (1)
	{
		flag = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
			{
				if (people[olimp[i][j]] == count)
				{
					flag = 1;
					if (j == 0)
					{
						people[olimp[i][1]] = min(count + 1, people[olimp[i][1]]);
						people[olimp[i][2]] = min(count + 1, people[olimp[i][2]]);
					}
					else if (j == 1)
					{
						people[olimp[i][0]] = min(count + 1, people[olimp[i][0]]);
						people[olimp[i][2]] = min(count + 1, people[olimp[i][2]]);
					}
					else if (j == 2)
					{
						people[olimp[i][0]] = min(count + 1, people[olimp[i][0]]);
						people[olimp[i][1]] = min(count + 1, people[olimp[i][1]]);
					}
				}
			}
		count++;
		if (flag == 0) break;
	}

	map <string, int>::iterator it;
	it = people.begin();
	for (; it != people.end(); it++)
	{
		fout << it->first << ' ';
		if (it->second != 101)
			fout << it->second << '\n';
		else fout << "undefined" << '\n';
	}

	return 0;
}