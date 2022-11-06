#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void sr_ar(vector<float>&pushka)
{
	float sum = 0;
	for (int i = 0; i < pushka.size(); i++)
		sum += pushka[i];
	pushka.push_back(sum / pushka.size());
}
void extrapolice(vector<float>&pushka)
{
	for (int i = 1; i < pushka.size(); i++)
	{
		pushka.insert(pushka.begin() + i, ((pushka[i - 1] + pushka[i]) / 2));
		i++;
	}
}
int main()
{
	vector<float>pushka(5);
	for (int i = 0; i < pushka.size(); i++)
		cin >> pushka[i];
	sr_ar(pushka);
	for (int i = 0; i < pushka.size(); i++)
		cout << pushka[i] << ' ';
	cout << '\n';
	extrapolice(pushka);
	for (int i = 0; i < pushka.size(); i++)
		cout << pushka[i] << ' ';

	system("pause");
	return 0;
}