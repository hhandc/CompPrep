#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    long long sum = 0;

    cin >> n >> m >> k;
    vector<pair<int, int>> cow(n);
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
    cin >> cow[i].first >> cow[i].second;
    }

    sort(cow.begin(), cow.end());

    q.push({ -1000000000, m });

    for (int i = 0; i < n; i++)
    {
    int cnt = 0;
    while (!q.empty() && cow[i].first - q.front().first >= k)
    {
    if(q.front().second <= cow[i].second) {
    sum += q.front().second;
    cnt += q.front().second;
    cow[i].second -= q.front().second;
    q.pop();

    if (cow[i].second == 0)
    break;
    }
            else if (q.front().second > cow[i].second)
            {
                q.front().second -= cow[i].second;
                sum += cow[i].second;
                cnt += cow[i].second;
                break;
            }
        }

        if (cnt != 0)
            q.push({ cow[i].first, cnt });
    }

    cout << sum;
    return 0;
}
