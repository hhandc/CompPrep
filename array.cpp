#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 1, maxc = 0;
vector<int> v;

int main()
{
    cin >> n;

    v.resize(n);

    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
    }

    for(int i = 0;i<n - 1;i++)
    {
        if(v[i] <= v[i + 1])
            cnt++;
        else
            cnt = 1;

        if(cnt > maxc)
            maxc = cnt;
    }

    cnt = 1;

    for(int i = n;i>0;i--)
    {
        if(v[i] >= v[i - 1])
            cnt++;
        else
            cnt = 1;

        if(cnt > maxc)
            maxc = cnt;
    }

    cout << maxc;

    return 0;
}