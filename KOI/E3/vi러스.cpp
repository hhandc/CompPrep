#include <iostream>
#include <vector>

using namespace std;

int n, m, sum = 0;
vector<vector<int>> connect;
vector<int> check;

void con(int s){
    check[s] = 1;

    for(int i = 0;i<connect[s].size();i++)
    {
        if(check[connect[s][i]] == 0)
        {
            sum++;
            con(connect[s][i]);
        }
    }

    return;
}

int main()
{
    cin >> n>> m;

    connect.resize(n + 1);
    check.resize(n + 1);

    for(int i= 0;i<m;i++)
    {
        int x, y;

        cin >> x >> y;

        connect[x].push_back(y);
        connect[y].push_back(x);
    }

    con(1);

    cout << sum;
    
    return 0;
}