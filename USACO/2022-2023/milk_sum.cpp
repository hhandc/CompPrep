#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<pair<long long, int>> cow(n);
    vector<long long> sums(n);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> cow[i].first;
        cow[i].second = i;
    }

    sort(cow.begin(), cow.end());

    vector<int> pointers(n);

    for (int i = 0; i < n; i++) {
        if (i == 0) 
            sums[i] = cow[i].first;
        else 
            sums[i] = cow[i].first + sums[i - 1];

        pointers[cow[i].second] = i;
        ans += cow[i].first * (i + 1);
    }

    int t;
    cin >> t;

    while (t--) {
        long long a, b;

        cin >> a >> b;

        a -= 1;

        long long now = ans - cow[pointers[a]].first * (pointers[a] + 1);

        if (cow[pointers[a]].first == b) {
            now += b * (pointers[a] + 1);
        }

        else if (cow[pointers[a]].first > b) {
            int i = lower_bound(cow.begin(), cow.end(), make_pair(b, 987654321)) - cow.begin();

            long long s = 0;

            if (pointers[a] > 0) s = sums[pointers[a] - 1];
            if (i > 0) s -= sums[i - 1];
            now += s;
            now += b * (i + 1);
        }
        else {
            int i = lower_bound(cow.begin(), cow.end(), make_pair(b, 0)) - cow.begin();
            long long s = sums[i - 1] - sums[pointers[a]];
            now -= s;
            now += b * i;
        }

        cout << now << "\n";
    }

    return 0;
}
