#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int l, r, temp = 0;
	float a, b, hold;
	cin >> l >> r;
	

	for (a = l; a <= r; a++)
	{
		for (b = a + 1; b <= r; b++)
		{
			if (a != 1)	hold = sqrt(a) - int(sqrt(a));
			else hold = 1;
			if (hold != 0)
			{
				hold = sqrt(b) - int(sqrt(b));
				if (hold != 0)
				{
					if (a != 1) hold = b / a;
					hold = hold - int(hold);
					if (hold != 0) temp++;
				}
			}
		}
	}

	cout << temp;

	return 0;
}