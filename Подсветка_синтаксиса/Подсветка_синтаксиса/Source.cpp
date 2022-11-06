#include <fstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool check(int n, char str[], char arr[][100]);
int main()
{
	string text;
	char arr[100][100], str[100];
	int i, n, hold = 0;
	bool flag = 0, flag_check = 0, flag_k = 0;
	str[0] = 0;

	fin >> n;
	for (i = 0; i < n; i++)
		fin >> arr[i];
	
	getline(fin, text, '\0');
	
	i = 0;
	text.erase(0, 1);
	while (text[i] != 0)
	{
		flag = isalnum(text[i]);
		if (flag == 1 || text[i] == '_')
		{
			str[hold] = text[i];
			hold++;
			str[hold] = 0;
		}
		else
		{
			if (text[i] == '"')
			{
				if (flag_k == 0)
				{
					text.insert(i - hold, "<i>");
					i += 3;
					flag_k = 1;
				}
				else
				{
					text.insert(i + 1, "</i>");
					i += 4;
					flag_k = 0;
				}
			}
			else if (flag_k != 1)
			{
				flag_check = check(n, str, arr);
				str[0] = 0;
				if (flag_check == 1)
				{
					text.insert(i - hold, "<b>");
					text.insert(i + 3, "</b>");
					i += 7;
				}
			}
			if (text[i] == '\n')
			{
				text.insert(i, "<br>");
				i += 4;
			}
			hold = 0;
		}
		i++;
	}

	text += "<br>";
	fout << text;

	return 0;
}

bool check(int n, char str[],char arr[][100])
{
	bool flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(str, arr[i]) == 0)
		{
			flag = 1;
			break;
		}
	}

	return flag;
}
