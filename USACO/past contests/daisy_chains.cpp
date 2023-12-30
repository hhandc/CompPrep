#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, i, j, sum = 0, cnt = 0, scnt = 0, avg, check = 0;
	vector<int> v;
	cin >> n;
	v.resize(n);

	for (i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				cnt++;
			else if (i < j)
			{
				for (int x = i; x <= j; x++)
				{
					sum += v[x];
					scnt++;
				}

				if (sum % scnt == 0)
				{
					avg = sum / scnt;
					for (int x = i; x <= j; x++)
					{
						if (v[x] == avg)
							check++;
					}
					if (check != 0)
						cnt++;
				}
			}
			sum = 0;
			scnt = 0;
			check = 0;
		}
	}

	cout << cnt;
	return 0;
}
