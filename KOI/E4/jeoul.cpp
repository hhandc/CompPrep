#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > bigger;
vector<vector<int > > smaller;
vector<vector<int> >  check;

void bsearch(int comp, int cur)
{
    for(int i = 0;i<bigger[comp].size();i++)
    {
        if(check[cur][bigger[comp][i]] == 0)
        {
            check[cur][bigger[comp][i]] = 1;

            if(bigger[bigger[comp][i]].size() > 0)
                bsearch(bigger[comp][i], cur);
        }
    }
}

void ssearch(int comp, int cur)
{
    for(int i = 0;i<smaller[comp].size();i++)
    {
        if(check[cur][smaller[comp][i]] == 0)
        {
            check[cur][smaller[comp][i]] = 1;

            if(smaller[smaller[comp][i]].size() > 0)
                ssearch(smaller[comp][i], cur);
        }
    }
}

int main(){
    cin >> n >> m;

    bigger.resize(n + 1);
    smaller.resize(n + 1);
    check.resize(n + 1, vector<int> (n + 1));

    for(int i = 0;i<m;i++)
    {
        int a, b;

        cin >> a >> b;

        bigger[a].push_back(b);
        smaller[b].push_back(a);
    }

    for(int i = 1;i<=n;i++)
    {
        if(bigger[i].size() > 0)
            bsearch(i, i);

        if(smaller[i].size() > 0)
            ssearch(i , i);
    }

    for(int i = 1;i<=n;i++)
    {
        int cnt = 0;

        for(int j = 1;j<=n;j++)
        {
            if(check[i][j] == 0)
                cnt++;
        }

        cout << cnt - 1 << '\n';
    }

    return 0;
}