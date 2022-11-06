#include <set>
#include <iostream>
using namespace std;
int main()
{
	set<int> arr;
	int hold, start, finish;
	cin >> hold;
	while (hold != -1) {
		arr.insert(hold);
		cin >> hold;
	}
	cin >> start;
	arr.insert(start);
	set <int>::iterator it_start = arr.find(start);
	cin >> finish;
	arr.insert(finish);
	set <int>::iterator it_finish = arr.find(finish);

	arr.erase(it_start, ++it_finish);
	
	for (set <int>::iterator it = arr.begin(); it != arr.end(); it++)
		cout << *it << ' ';
	system("pause");
	return 0;
}