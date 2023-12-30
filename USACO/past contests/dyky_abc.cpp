#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int max = 0;
	int n, i, j, x, comp, h;
	vector<int> v;
	vector<int> abc;


	for (i = 0; i < 7; i++)
	{
		cin >> n;
		v.push_back(n);
	}

	for (i = 0; i < 7; i++)
	{
		if (v[i] >= max)
		{
			max = v[i];
			comp = i;
		}
	}

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			for (x = 0; x <7;x++)
			{
				if (i == comp || j == comp || x == comp) continue;
				else if (v[i] + v[j] + v[x] == max)
				{
					abc.push_back(v[i]);
					abc.push_back(v[j]);
					abc.push_back(v[x]);
				}
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (abc[i] < abc[j] && i > j)
			{			
				h = abc[i];
				abc[i] = abc[j];
				abc[j] = h;
			}
		}
	}

	for (i = 0; i < 3; i++) {
		cout << abc[i] << ' ';
	}

	return 0;
}
