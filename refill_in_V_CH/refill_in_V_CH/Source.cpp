#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct soldier_p{
	char c;
	int num;
	soldier_p * sold;
};

int main(){
	int i, j, n, m, l, k;
	soldier_p * soldiers_p = (soldier_p*)malloc(sizeof(soldier_p));
	soldier_p * first_p = (soldier_p*)malloc(sizeof(soldier_p));
	soldier_p * soldiers_n[100];
	fin >> n >> m >> l >> k;

	for (i = 0; i < n; i++)	{
		soldiers_p->sold = (soldier_p*)malloc(sizeof(soldier_p));
		soldiers_p->c = 'p';
		soldiers_p->num = i + 1;
		if (i == 0) first_p = soldiers_p;
		if (i != n - 1) soldiers_p = soldiers_p->sold;
		else if (i == n - 1) soldiers_p->sold = first_p;
	}
	for (j = 0; j < m; j++)	{
		soldiers_n[j] = (soldier_p*)malloc(sizeof(soldier_p));
		soldiers_n[j]->c = 'n';
		soldiers_n[j]->num = j + 1;
	}
	for (soldiers_p = first_p; l > 1; l--)
		soldiers_p = soldiers_p->sold;
	for (j = 0; j < m; j++)	{
		for (i = 1; i < k - 1; i++)		
			soldiers_p = soldiers_p->sold;
		soldiers_n[j]->sold = soldiers_p->sold;
		soldiers_p->sold = soldiers_n[j];
		soldiers_p = soldiers_p->sold->sold;
	}
	for (soldiers_p = first_p, i = 0; i < n + m; i++)	{
		fout << soldiers_p->c << soldiers_p->num << ' ';
		soldiers_p = soldiers_p->sold;
	}
	return 0;
}