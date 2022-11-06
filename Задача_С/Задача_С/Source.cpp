#include <iostream>

using namespace std;

int main()
{
	int i, r, ln;
	char str[3], divizion;
	bool flag = 0;

	cin >> r >> str;

	ln = strlen(str);

	if (r > 1900) divizion = '1';
	else if (r > 1600) divizion = '2';
	else divizion = '3';
	
	for (i = 0; i < ln; i++)
	{
		if (str[i] == divizion) flag = 1;
	}

	if (flag == 1)
	{
		cout << divizion;
		return 0;
	}

	for (i = 0; i < ln; i++)
	{
		if (r > 1900)
		{
			cout << str[i] << '*' << '\n';
		}
		else if (r > 1600)
		{
			if (str[i] == '1')
			{
				cout << str[i] << '\n';
			}
			else if (str[i] == '3')
			{
				cout << str[i] << '*';
			}
		}
		else
		{
			if (str[i] == '1')
			{
				cout << str[i] << '\n';
			}
			else if (str[i] == '2')
			{
				cout << str[i] << '\n';
			}
		}
	}

	return 0;
}