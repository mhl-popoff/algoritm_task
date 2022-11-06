#include <fstream>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int main()
{
	int i = 0, j = 0, k = 0, quantity_E = 0, quantity_W = 0, quantity_S = 0, quantity_N = 0;
	char c[202], c_hold[202], hold_swap;
	fin >> c;
	int len;
	len = strlen(c);
	i = len - 1;
	while (i >= 0)
	{
		if (c[i] == 'W') {
			if (quantity_E == 0) {
				quantity_W++;
				c_hold[j] = c[i];
				j++;
			}
			else {
				quantity_E -= 1;
				for (k = 0; k < j; k++) {
					if (c_hold[k] == 'E') {
						hold_swap = c_hold[k];
						c_hold[k] = c_hold[k + 1];
						c_hold[k + 1] = hold_swap;
					}
				}
				j--;
			}
		}
		else if (c[i] == 'S') {
			if (quantity_N == 0) {
				quantity_S++;
				c_hold[j] = c[i];
				j++;
			}
			else {
				quantity_N -= 1;
				for (k = 0; k < j; k++)	{
					if (c_hold[k] == 'N') {
						hold_swap = c_hold[k];
						c_hold[k] = c_hold[k + 1];
						c_hold[k + 1] = hold_swap;
					}
				}
				j--;
			}
		}
		else if (c[i] == 'E') {
			if (quantity_W == 0) {
				quantity_E++;
				c_hold[j] = c[i];
				j++;
			}
			else {
				quantity_W -= 1;
				for (k = 0; k < j; k++)	{
					if (c_hold[k] == 'W') {
						hold_swap = c_hold[k];
						c_hold[k] = c_hold[k + 1];
						c_hold[k + 1] = hold_swap;
					}
				}
				j--;
			}
		}
		else if (c[i] == 'N') {
			if (quantity_S == 0) {
				quantity_N++;
				c_hold[j] = c[i];
				j++;
			}
			else {
				quantity_S -= 1;
				for (k = 0; k < j; k++)	{
					if (c_hold[k] == 'S') {
						hold_swap = c_hold[k];
						c_hold[k] = c_hold[k + 1];
						c_hold[k + 1] = hold_swap;
					}
				}
				j--;
			}
		}
		i--;
	}
	for (i = 0; i < j; i++)	{
		if (c_hold[i] == 'S') fout << 'N';
		if (c_hold[i] == 'N') fout << 'S';
		if (c_hold[i] == 'W') fout << 'E';
		if (c_hold[i] == 'E') fout << 'W';
	}
	return 0;
}
