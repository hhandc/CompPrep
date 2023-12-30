#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> cow;

int minanswer(void) {
	if (cow[n - 2] - cow[0] == n - 2 && cow[n - 1] - cow[n - 2] > 2) 
		return 2;
	if (cow[n - 1] - cow[1] == n - 2 && cow[1] - cow[0] > 2)
		return 2;

	int i, j = 0, best = 0;

	for (i = 0; i < n; i++)
	{
		while (j < n - 1 && cow[j + 1] - cow[i] <= n - 1)
			j++;
		best = max(best, j - i + 1);
	}

	return n - best;
}

int solve_min(void)
{
	if (cow[n - 2] - cow[0] == n - 2 && cow[n - 1] - cow[n - 2] > 2) return 2;
	if (cow[n - 1] - cow[1] == n - 2 && cow[1] - cow[0] > 2) return 2;
	int i, j = 0, best = 0;
	for (i = 0; i < n; i++) {
		while (j < n - 1 && cow[j + 1] - cow[i] <= n - 1) j++;
		best = max(best, j - i + 1);
	}
	return n - best;
}

int main()
{
	int min, maxi;

	cin >> n;
	cow.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cow[i];
	}

	sort(cow.begin(), cow.end());

	min = minanswer();
	maxi = max(cow[n - 2] - cow[0], cow[n - 1] - cow[1]) - (n - 2);

	cout << min << '\n' << maxi;
	return 0;
}
