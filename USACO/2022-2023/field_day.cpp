#include <iostream>
#include <vector>

using namespace std;

int n, c, ma = 0;
string s;
vector<string> team;
vector<int> diff;
vector<int> ans;

int main()
{
	cin >> c >> n;

	team.resize(n);
	diff.resize(n);
	ans.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> team[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			diff[j] = 0;

			if (j != i)
			{
				for (int k = 0; k < c; k++)
				{
					if (team[i][k] != team[j][k])
						diff[j] += 1;
				}

				if (diff[j] > ans[i]) {
					ans[i] = diff[j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
