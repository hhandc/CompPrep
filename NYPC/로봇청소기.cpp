#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt = 0, acnt = 0;
vector<string> grid;
vector<vector<int>> pol;
vector<string> ans;
vector<int> stans;

int main()
{
    cin >> n >> m;

    grid.resize(n);
    pol.resize(n, vector<int>(m));

    for(int i = 0;i<n;i++)
    {
        cin >> grid[i];
    }

    for(int i = 0;i<m;i++)
    {
        int a = 0;
        for(int j = n - 1;j>=0;j--)
        {
            if(grid[j][i] == 'X')
            {
                a++;
                cnt++;
                pol[j][i] = a;
            }
            else   
                pol[j][i] = a;
        }
    }

    while(cnt !=  0)
    {
        acnt++;
        int max = 0;

        for(int i = 0;i<m;i++)
        {
            if(pol[0][i] > pol[0][max])
                max = i;
        }

        stans.push_back(max);

        if(grid[0][max] == 'X')
        {
            cnt--;
            pol[0][max] -= 1;
        }

        for(int i = 0;i<n - 1;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(max - j >= 0 && max - j < m){
                    
                }
            }
            
        }
    }
}