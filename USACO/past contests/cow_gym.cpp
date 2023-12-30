#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k, n, i, j, m, cnt = 0;;
	cin >> k >> n;
	vector<int> v(n + 1);
	vector<int> c(n + 1);
	vector<vector<int>> list(n + 1, vector<int>(n + 1));
	vector<vector<int>> clist(n + 1, vector<int>(n + 1));


	for (i = 0; i < n; i++)
	{
		cin >> m;
		v[m] = i + 1;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (v[i] < v[j])
				list[i][j] = 1;
			else if (v[i] >= v[j])
				list[i][j] = 0;
		}
	}

	for (i = 0; i < k - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> m;
			c[m] = j + 1;
		}

		for (j = 1; j <= n; j++)
		{
			for (int o = 1; o <= n; o++)
			{
				if (c[j] < c[o])
				{
					clist[j][o] = 1;
					if (list[j][o] == 1)
						continue;
					else if (list[j][o] == 0)
						continue;
				}
				else if (c[j] >= c[o])
				{
					clist[j][o] = 0;
					if (list[j][o] == 0)
						continue;
					else if (list[j][o] == 1)
						list[j][o] = 0;
				}
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (list[i][j] == 1)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}
