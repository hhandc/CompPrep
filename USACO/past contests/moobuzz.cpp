#include <iostream>

using namespace std;

int main()
{
	int n, m = 0, o = 0, x = 0, ans = 0;
	bool b = true;
	cin >> n;

	int num[10] = {2, 1, 2, 1, 2, 2, 1, 2, 1, 2 }; // 16
	int moo[10] = {1, 2, 2, 1, 1, 1, 2, 2, 1, 1 }; // 14

	if (n % 16 == 0)
		ans = -1;

	ans += (n / 16) * 30;
	n -= n / 16 * 16;

	while (1)
	{
		if (m > n) {
			cout << ans - 1;
			break;
		}
		else if (m == n)
		{
			cout << ans;
			break;
		}

		if (b == true)
		{
			ans += num[o];
			m += num[o];
			o++;
			b = false;
		}
		else {
			ans += moo[x];
			x++;
			b = true;
		}

		if (o == 10)
			o = 0;
		if (x == 10)
			x = 0;
	}
	return 0;
}
