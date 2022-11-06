#include <fstream>
using namespace std;
std :: ifstream fin("input.txt");
std :: ofstream fout("output.txt");

int lader(int n, int distinct) {
	int steps = 0;
	if (n < 2) return 1;
	if ((n == 2) && (distinct == 1)) return 0;
	if ((n == 2) && (distinct >=2)) return 1;

	for (int i = 0; i < n ; i++) {		
		if (n - i <= distinct)
			steps += lader(i, n - i - 1);
	}
	return steps;
}
int main() {
	int n;
	fin >> n;
	fout << lader(n, n);
	return 0;
}