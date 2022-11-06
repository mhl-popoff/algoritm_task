#include <iostream>

using namespace std;

struct gate {
	int last_index = -1;
	int is_open = 0;
};

int main()
{
	int n, k;
	cin >> n >> k;
	char str[1000000];
	cin >> str;
	gate gates[26];
	for (int i = n - 1; i >= 0; i--)
	{
		int num_letter = (int)(str[i] - 'A');
		if (gates[num_letter].last_index == -1)
			gates[num_letter].last_index = i;
	}

	int n_sequrity = 0;
	for (int i = 0; i < n; i++)
	{
		int num_letter = (int)(str[i] - 'A');
		if (gates[num_letter].is_open == 0)
		{
			gates[num_letter].is_open = 1;
			n_sequrity++;
		}
		if (n_sequrity > k)
		{
			cout << "YES";
			return 0;
		}
		if (i == gates[num_letter].last_index) n_sequrity--;
	}


	cout << "NO";
	return 0;
}