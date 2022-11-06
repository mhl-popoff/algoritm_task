#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct MyStruct
{
	float x;
	float y;
	string kind;
	int litre;
};

struct MyStruct_2
{
	string kind;
	int litre;
	bool flag = 0;
};

int main()
{
	MyStruct gsm[100];
	MyStruct_2 result[100];
	int i, n;
	float x_brig, y_brig, r_brig;
	int hold = 0;
	fin >> n;
	
	for (i = 0; i < n; i++)
	{
		fin >> gsm[i].x >> gsm[i].y >> gsm[i].kind >> gsm[i].litre;
	}

	fin >> x_brig >> y_brig >> r_brig;

	for (i = 0; i < n; i++)
	{
		if ((x_brig - gsm[i].x) * (x_brig - gsm[i].x) + (x_brig - gsm[i].x) * (x_brig - gsm[i].x) <= r_brig * r_brig)
		{
			result[i].kind = gsm[i].kind;
			result[i].litre = gsm[i].litre;
		}
		else
		{
			result[i].kind = gsm[i].kind;
			result[i].litre = 0;
		}
	}



	for (i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (result[i].kind == result[j].kind)
			{
				result[i].litre += result[j].litre;
				result[j].flag = 1;
			}
		}
		
	}
	
	for (i = 0; i < n; i++)
	{
		if (result[i].flag != 1)
			fout << result[i].kind << " : " << result[i].litre << '\n';
	}

	return 0;
}