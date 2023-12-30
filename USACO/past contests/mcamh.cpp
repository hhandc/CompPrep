#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	

	long long n, sum = 0, avg1 = 0, avg2 = 0, min = 10000000, ansmax1 = -1, ansmax2 = 1;
	
	cin >> n;

	vector<int> q(n + 1);
	vector<int> answer;

	for (int i = 1; i <= n; i++)
	{
		cin >> q[i];
	}

	min = n;
	sum += q[n];

	for (int i = n - 1; i > 1; i--)
	{
		if (q[i] < q[min]) {
			min = i;
			avg1 = sum;
			avg2 = (n - i);
			sum += q[i];
		}

		else {
			sum += q[i];
			sum -= q[min];
			avg1 = sum;
			avg2 = (n - i);
			sum += q[min];
		}

		if (avg1 * ansmax2 > avg2 * ansmax1)
		{
			answer.clear();
			answer.push_back(i - 1);
			ansmax1 = avg1;
			ansmax2 = avg2;
		}

		else if (avg1 * ansmax2 == avg2 * ansmax1)
			answer.push_back(i - 1);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		if (i == 0)
			cout << answer[i];
		else
			cout << "\n" << answer[i];
	}

	return 0;
}
