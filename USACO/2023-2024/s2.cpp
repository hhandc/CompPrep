#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k,max = 0;

	cin >> n >> k;

	vector<int> A(k);
	vector<int> index(n + 1);
	vector<int> B(k);
	vector<int> flip(k);
	vector<int> count(k);
	vector<int> fcount(k);
	vector<int>check(n + 1);
	vector<int> bcheck(n + 1);

	for (int i = 0; i < k; i++)
	{
		cin >> A[i];
		index[A[i]] = i;
		check[A[i]] = 1;
	}

	for (int i = 0; i < k; i++)
	{
		cin >> B[i];
		flip[k - i - 1] = B[i];
		bcheck[B[i]] = 1;
	}

	for (int i = 0; i < k; i++)
	{
		if (check[B[i]] == 1)
		{
			if (index[B[i]] > i)
			{
				count[index[B[i]] - i]++;
				if (max < count[index[B[i]]])
					max = count[index[B[i]]];
			}
			else if (index[B[i]] < i)
			{
				count[k + index[B[i]] - i]++;
				if (max < count[k + index[B[i]] - i])
					max = count[k + index[B[i]] - i];
			}
			else
			{
				count[0]++;
				if (max < count[0])
					max = count[0];
			}

			if (index[flip[i]] > i)
			{
				fcount[index[flip[i]] - i]++;
				if (max < fcount[index[flip[i]]])
					max = fcount[index[flip[i]]];
			}
			else if (index[flip[i]] < i)
			{
				fcount[k + index[flip[i]] - i]++;
				if (max < fcount[k + index[flip[i]] - i])
					max = fcount[k + index[flip[i]] - i];
			}
			else
			{
				fcount[0]++;
				if (max < fcount[0])
					max = fcount[0];
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (check[i] == 0 && bcheck[i] == 0)
			max++;
	}

	cout << max;

	return 0;
}