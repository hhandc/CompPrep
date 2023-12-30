#include <iostream>

using namespace std;

int a[2001][2001] = {};

int main()
{
    int n, m, x1, y1, x2, y2, cnt = 0;
    
    for(int i = 0;i<2;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int j = x1 + 1000;j< x2 + 1000;j++)
        {
            for(int k = y1 + 1000;k<y2 + 1000;k++)
            {
                a[j][k] = 1;
            }
        }
    }
    
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 + 1000;i<x2 + 1000;i++)
    {
        for(int j = y1 + 1000;j<y2 + 1000;j++)
        {
            a[i][j] = 0;
        }
    }
    
    for(int i = 0;i<2001;i++)
    {
        for(int j = 0;j<2001;j++)
        {
            if(a[i][j] == 1)
                cnt++;
        }
    }
    
    cout << cnt;
    return 0;
}
