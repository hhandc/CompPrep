#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > connect;
vector<vector<int> > back;
vector<vector<int> > check;

void bsearch(int x, int carr) {
    for(int i = 0;i<back[x].size();i++) {
        check[carr][back[x][i]] = 1;

        if(connect[back[x][i]].size() > 0)
            csearch(connect[x][i], carr);

        if(back[back[x][i]].size() > 0)
            bsearch(back[x][i], carr);
    }
}

void csearch(int x, int carr) {
    for(int i = 0;i<connect[x].size();i++) {
        check[carr][connect[x][i]] = 1;

        if(connect[connect[x][i]].size() > 0)
            csearch(connect[x][i], carr);

        if(back[connect[x][i]].size() > 0)
            bsearch(connect[x][i], carr);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    connect.resize(n + 1);
    back.resize(n + 1);
    check.resize(n + 1, vector<int>(n + 1));

    for(int i = 0;i<m;i++)
    {
        int a, b;

        cin >> a >> b;

        connect[a].push_back(b);
        back[b].push_back(a);
    }

    for(int i = 1;i<=n;i++)
    {
        int cnt = 0;

        if(connect[i].size() > 0)
            csearch(i, i);

        if(back[i].size() > 0)
            bsearch(i , i);

        for(int j = 1;j<=n;j++)
        {
            if(check[i][j] == 0)
                cnt++;
        }

        cout << cnt - 1 << '\n';
    }

    return 0;
}