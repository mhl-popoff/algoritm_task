#include <fstream>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int new_partition(int prev_level, int n) {
	if (n == 0)
		return 1;
	int count = 0;
	for (int level = 1; level < prev_level; level++) {
		if ((n - level) < 0)
			break;
		count += new_partition(level, n - level);
	}
	return count;
}
int main() {
	int n;
	fin >> n;
	fout << new_partition(n + 1, n);
	return 0;
}