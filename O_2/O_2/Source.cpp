//#include <fstream>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//ifstream fin("input.txt");
//ofstream fout("output.txt");
//struct exam
//{
//	long marks;
//	long referat;
//};
//int main()
//{
//	long n, r, referate_max = 0;
//	double avg, my_avg, sum_marks = 0;
//	fin >> n >> r >> avg;
//	exam * exams[100001], * min;
//	min = (exam*)malloc(sizeof(exam));
//	min->referat = 1000001;
//	for (int i = 0; i < n; i++)	{
//		exams[i] = (exam*)malloc(sizeof(exam));
//		fin >> exams[i]->marks >> exams[i]->referat;
//		sum_marks += exams[i]->marks;
//		if (min->referat > exams[i]->referat && exams[i]->marks != r) min = exams[i];
//	}
//	my_avg = sum_marks / n;
//	while (my_avg < avg)
//	{
//		sum_marks = 0;
//		referate_max += min->referat; 
//		if (min->marks < r) min->marks++;
//		if (min->marks == r)
//		{
//			min->referat = 1000000;
//			for (int i = 0; i < n; i++)
//				if (min->referat > exams[i]->referat && exams[i]->marks != r) min = exams[i];
//		}
//		for (int i = 0; i < n; i++)
//			sum_marks += exams[i]->marks;
//		my_avg = sum_marks / n;	
//	}
//	fout << referate_max;
//	return 0;
//}
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
struct emeny
{
	int id;
	int distance;
};
bool my_sort(emeny * a1, emeny * a2)
{
	if (a1->distance < a2->distance)
		return true;
	return false;
}
int main()
{
	int n, x, y, kill = 0;
	fin >> n;
	vector<emeny*>drones(n);
	for (int i = 0; i < n; i++)	{
		drones[i] = (emeny*)malloc(sizeof(emeny));
		drones[i]->id = i + 1;
		fin >> x >> y;
		drones[i]->distance = max(abs(x), abs(y));
	}
	sort(drones.begin(), drones.end(), my_sort);
	for (int i = 0; i < n ; i++) {
		kill++;
		if (drones[i]->distance < kill) {
			fout << -1;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		fout << drones[i]->id << ' ';
	}
	return 0;
}