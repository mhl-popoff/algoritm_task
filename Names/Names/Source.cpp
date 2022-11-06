#include <fstream>
#include <string>
#include <string.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	char str_1[100005];
	char str_2[100005];
	
	char hold[100005];
	hold[0] = 0;
	
	fin >> str_1;
	fin >> str_2;
	
	int i = 0;
	bool flag = 0;
	char temp, temp_error, temp_my;

	char * p_1 = str_1;
	char * p_2 = str_2;
	char * p_start = str_2;

	while (flag == 0)
	{
		temp = str_1[0];
		for (i = 0; str_1[i] != 0; i++)
		{
			if (temp < str_1[i])
			{
				temp = str_1[i];
			}
		}
		for (i = 0; str_2[i] != 0; i++)
		{
			if (temp == str_2[i])
			{
				flag = 1;
				break;
			}
			if (temp == 0)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			temp_error = temp;
			temp = 0;
			p_1 = str_1;
			while (*(p_1 - 1) != 0)
			{
				if (*p_1 == temp_error)
				{
					temp_my = *p_1;
					*p_1 = *(p_1 + 1);
					*(p_1 + 1) = temp_my;
				}
				if ((*p_1 == 0) && (temp != 0))
					flag = 1;
				if (*p_1 != 0) p_1++;
				else break;
			}
		}
	}

	p_1 = str_1;
	p_2 = str_2;
	i = 0;

	while (*p_1 != 0)
	{
		if (temp == *p_1)
		{
			p_start = p_2;
			while (*p_2 != 0)
			{
				if (temp == *p_2)
				{
					hold[i] = temp;
					i++;
					hold[i] = 0;
					temp = *(p_1 + 1);
					p_2++;

					break;
				}
				p_2++;
				if (*p_2 == 0)
				{
					p_2 = p_start;
					temp = *(p_1 + 1);
					break;
				}
			}
		}
		p_1++;
	}

	fout << hold;

	return 0;
}






//int main()
//{
//	char str_1[100005];
//	char str_2[100005];
//
//	char hold[100005];
//	hold[0] = 0;
//
//	fin >> str_1;
//	fin >> str_2;
//
//	int i = 0;
//	bool flag = 0;
//	char temp, temp_error, temp_my;
//
//	char * p_1 = str_1;
//	char * p_2 = str_2;
//	char * p_start = str_2;
//
//	while (flag == 0)
//	{
//		temp = str_1[0];
//		for (i = 0; str_1[i] != 0; i++)
//		{
//			if (temp < str_1[i])
//			{
//				temp = str_1[i];
//			}
//		}
//		for (i = 0; str_2[i] != 0; i++)
//		{
//			if (temp == str_2[i])
//			{
//				flag = 1;
//				break;
//			}
//			if (temp == 0)
//			{
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//		{
//			temp_error = temp;
//			temp = 0;
//			p_1 = str_1;
//			while (*(p_1 - 1) != 0)
//			{
//				if (*p_1 == temp_error)
//				{
//					temp_my = *p_1;
//					*p_1 = *(p_1 + 1);
//					*(p_1 + 1) = temp_my;
//				}
//				if ((*p_1 == 0) && (temp != 0))
//					flag = 1;
//				if (*p_1 != 0) p_1++;
//				else break;
//			}
//		}
//	}
//
//	p_1 = str_1;
//	p_2 = str_2;
//	i = 0;
//
//	while (*p_1 != 0)
//	{
//		if (temp == *p_1)
//		{
//			if (*p_2 != 0 && temp <= hold[i - 1] || i == 0)
//			{
//				p_start = p_2;
//				while (*p_2 != 0)
//				{
//					if (temp == *p_2)
//					{
//						hold[i] = temp;
//						i++;
//						hold[i] = 0;
//						temp = *(p_1 + 1);
//						p_2++;
//
//						break;
//					}
//					p_2++;
//					if (*p_2 == 0)
//					{
//						p_2 = p_start;
//						temp = *(p_1 + 1);
//						break;
//					}
//				}
//			}
//			else if (*p_2 == 0 || temp >= hold[i - 1])
//			{
//				if (*p_2 == 0 ) 
//				p_2 = p_start;
//				while (*p_2 != 0)
//				{
//					if (temp == *p_2)
//					{
//						hold[i - 1] = temp;
//						hold[i] = 0;
//						temp = *(p_1 + 1);
//						p_2++;
//
//						break;
//					}
//					p_2++;
//					if (*p_2 == 0)
//					{
//						p_2 = p_start;
//						temp = *(p_1 + 1);
//						break;
//					}
//				}
//			}
//		}
//		p_1++;
//	}
//
//	fout << hold;
//
//	return 0;
//}