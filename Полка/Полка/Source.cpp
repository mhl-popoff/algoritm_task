#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef struct polka {
	int number;
	polka * left = NULL;
	polka * right = NULL;
}polka;



int main()
{
	short int n, i, hold;
	fin >> n;

	polka * t = (polka*)malloc(sizeof(polka));
	fin >> hold;
	fin >> t->number;
	t->left = NULL;
	t->right = NULL;

	polka * left_ptr = t, *right_ptr = t;

	for (i = 0; i < n-1; i++)
	{
		fin >> hold;
		switch (hold)
		{
		case 1:
/*			if (i == 0)
			{
				fin >> t->number;
				break;
			}
			else*/
			if (left_ptr == NULL) {//если полка пуста
				left_ptr = (polka*)malloc(sizeof(polka));
				right_ptr = left_ptr;
				left_ptr->left = NULL;
				fin >> left_ptr->number;
				left_ptr->right = NULL;
				break;
				}
			else{
				left_ptr->left = (polka*)malloc(sizeof(polka));
				left_ptr->left->left = NULL;
				fin >> left_ptr->left->number;
				left_ptr->left->right = left_ptr;
				left_ptr = left_ptr->left;
				break;
			}
		case 2:
/*			if (i == 0)
			{
				fin >> t->number;
				break;

			}
			else */
			if (left_ptr == NULL) {//если полка пуста
				left_ptr = (polka*)malloc(sizeof(polka));
				right_ptr = left_ptr;
				left_ptr->left = NULL;
				fin >> left_ptr->number;
				left_ptr->right = NULL;
				break;
			}
			else
			{
				right_ptr->right = (polka*)malloc(sizeof(polka));
				right_ptr->right->right = NULL;
				fin >> right_ptr->right->number;
				right_ptr->right->left = right_ptr;
				right_ptr = right_ptr->right;

				break;

			}
		case 3:
			fout << left_ptr->number << " ";
			if (left_ptr->right != NULL) {
				left_ptr = left_ptr->right;
				left_ptr->left = NULL;
			}
			else {
				left_ptr = NULL;
				right_ptr = NULL;
			}
			break;

		case 4:
			fout << right_ptr->number << " ";
			if (right_ptr->left != NULL) {
				right_ptr = right_ptr->left;
				right_ptr->right = NULL;
			}
			else {
				left_ptr = NULL;
				right_ptr = NULL;
			}
			break;

		default:
			break;
		}

//		fout << "\n" << left_ptr;
//		fout << "\n" << right_ptr;
		
	}
//	fout << "\n" << left_ptr;
//	fout << "\n" << right_ptr;


	return 0;
}