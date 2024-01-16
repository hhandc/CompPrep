#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > line;

int main()
{
    int n, ma = 0;
    cin >> n;

    line.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> line[i].second >> line[i].first;
    }

    sort(line.begin(), line.end());

    vector<int> dp(n);
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if(line[i].second > line[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for(int i = 0;i<n;i++)
    {
        if(ma < dp[i])
            ma = dp[i];
    }

    cout << n - ma;

    return 0;
}