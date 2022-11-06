#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

string check(int n, char arr[][100], string str);


int main()
{
	int n, i, hold = 0;
	char arr[100][100], slovo[100];
	string str, text, str_hold;
	bool flag = 0;

	fin >> n;

	for (i = 0; i < n; i++)
		fin >> arr[i];

	i = 0;
	getline(fin, text, '\0');
	while (text[i] != 0)
	{
		flag = isalpha(text[i]);
		if (flag == 1)
		{
			str += text[i];
			hold++;
		}
		if (flag == 0 || text[i + 1] == 0)
		{
			str_hold = check(n, arr, str);
			if (str != str_hold)
			{
				text.replace(i - (hold - 0), hold, str_hold);
				
			}
			str.erase();
			hold = 0;
		}
		i++;
	}

	fout << text;

	return 0;
}

string check(int n, char arr[][100], string str)
{
	string slovo;
	bool flag = 0, flag_error = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; arr[i][j] != '\0'; j++)
		{
			if (str[j] == 0)
			{
				flag = 0;
				break;
			}
			if (arr[i][j] != str[j])
			{
				if (flag == 1)
				{
					flag_error = 1;
					break;
				}
				flag = 1;
			}
		}
		if (flag == 1 && flag_error == 0)
		{
			return arr[i];
		}
		else if (i < n - 1)
		{
			flag = 0;
			flag_error = 0;
		}
	}
	slovo = str;

	return slovo;
}