#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int l, w, maxh = 0;
vector<string> grid;
vector<vector<int>> check;
queue<pair<int, int>> q;
queue<pair<int, int>> reset;
queue<int> cnt;
pair<int, int> cord;

int main() {
	cin >> l >> w;
	grid.resize(l);
	check.resize(l, vector<int>(w));

	for (int i = 0; i < l; i++)
	{
		cin >> grid[i];
	}

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (grid[i][j] == 'L')
			{
			    check[i][j] = 1;
				q.push({ i, j });
				cnt.push(0);

				while (!q.empty())
				{
					int hour = cnt.front();
					cnt.pop();
					cord = q.front();
					q.pop();
					int x = cord.first;
					int y = cord.second;
					if (hour < check[x][y] || check[x][y] == 0)
					{
						check[x][y] = hour;
						reset.push({ x, y });

						if (x + 1 < l && grid[x + 1][y] == 'L' && check[x + 1][y] == 0)
						{
							q.push({ x + 1, y });
							cnt.push(hour + 1);
						}
						if (x - 1 >= 0 && grid[x - 1][y] == 'L' && check[x - 1][y] == 0)
						{
							q.push({ x - 1, y });
							cnt.push(hour + 1);
						}
						if (y + 1 < w && grid[x][y + 1] == 'L' && check[x][y + 1] == 0)
						{
							q.push({ x, y + 1 });
							cnt.push(hour + 1);
						}
						if (y - 1 >= 0 && grid[x][y - 1] == 'L' && check[x][y - 1] == 0)
						{
							q.push({ x, y - 1 });
							cnt.push(hour + 1);
						}
					}
				}

				while (reset.empty() == false)
				{
					if (check[reset.front().first][reset.front().second] > maxh)
						maxh = check[reset.front().first][reset.front().second];
					check[reset.front().first][reset.front().second] = 0;
					reset.pop();
				}
			}
		}
	}
	cout << maxh;
}
