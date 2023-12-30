#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, cnt = 0, p;
	
	cin >> n;

	cnt = n;
	vector<int> to(n + 1);
	vector<int> from(n + 1);
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		from[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> to[i];
		from[to[i]]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (from[i] == 0) {
			cnt--;
			q.push(i);
		}
	}

	while (q.empty() != true)
	{
		p = q.front();
		q.pop();
		
		from[to[p]]--;

		if (from[to[p]] == 0) {
			q.push(to[p]);
			cnt--;
		}
	}

	cout << cnt;
	return 0;
}
