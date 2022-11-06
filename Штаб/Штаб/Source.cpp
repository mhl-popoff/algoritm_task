#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct kp {
	bool s = 0;
	bool e = 0;
	bool n = 0;
	bool w = 0;
	int color = 0;
	int coordinate = 0;
};

int opredelitel_s(int x) {
	if (x - 8 >= 0) 
		return 1;
	return 0;
}

int opredelitel_e(int x) {
	if (x - 4 >= 0)
		return 1;
	return 0;
}

int opredelitel_n(int x) {
	if (x - 2 >= 0)
		return 1;
	return 0;
}

int opredelitel_w(int x) {
	if (x - 1 >= 0)
		return 1;
	return 0;
}

int paint(kp com_centr[10][10], int i_h, int j_h, int color, int counter) {
	com_centr[i_h][j_h].color = color;
	counter++;
	if (com_centr[i_h][j_h + 1].color == 0 && com_centr[i_h][j_h].e == 0)
		counter = paint(com_centr, i_h, j_h + 1, color, counter);
	if (com_centr[i_h][j_h - 1].color == 0 && com_centr[i_h][j_h].w == 0)
		counter = paint(com_centr, i_h, j_h - 1, color, counter);
	if (com_centr[i_h + 1][j_h].color == 0 && com_centr[i_h][j_h].s == 0)
		counter = paint(com_centr, i_h + 1, j_h, color, counter);
	if (com_centr[i_h - 1][j_h].color == 0 && com_centr[i_h][j_h].n == 0)
		counter = paint(com_centr, i_h - 1, j_h, color, counter);
	return counter;
}

int main() {
	int n, m;
	fin >> n >> m;
	int sum[50];
	kp com_centr[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum[j] = 0;
			fin >> com_centr[i][j].coordinate;
			if (com_centr[i][j].s = opredelitel_s(com_centr[i][j].coordinate) == 1)
				com_centr[i][j].coordinate -= 8;
			if (com_centr[i][j].e = opredelitel_e(com_centr[i][j].coordinate) == 1)
				com_centr[i][j].coordinate -= 4;
			if (com_centr[i][j].n = opredelitel_n(com_centr[i][j].coordinate) == 1)
				com_centr[i][j].coordinate -= 2;
			if (com_centr[i][j].w = opredelitel_w(com_centr[i][j].coordinate) == 1)
				com_centr[i][j].coordinate -= 1;
		}
	}
	int color = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (com_centr[i][j].color == 0) {
				sum[color] = paint(com_centr, i, j, color, sum[color]);
				color++;
			}
		}
	}
	fout << color - 1 << endl;
	int max = 0;
	for (int i = 1; i < color; i++) {
		if (sum[i] > max)
			max = sum[i];
	}
	fout << max;
	return 0;
}