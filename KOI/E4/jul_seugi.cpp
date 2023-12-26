#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt = 1, ma = 0;
vector<pair<int, int> > line;

int main()
{
    cin >> n;

    line.resize(n);

    for(int i = 0;i<n;i++)
    {
        cin >> line[i].first;

        line[i].second = i;
    }

    sort(line.begin(), line.end());

    for(int i = 0;i<n - 1;i++)
    {
        if(line[i].second < line[i + 1].second)
            cnt++;
        else
            cnt = 1;
        
        if(ma < cnt)
            ma = cnt;
    }
    
    if(n == 1)
        cout << "0";
    else if(ma == 1)
        cout << n;
    else
        cout << n - ma;

    return 0;
}