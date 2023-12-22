#include <iostream>
#include <vector>

using namespace std;

vector<int> xs;
vector<int> ys;

int n, m, k, t;
int ansx, ansy, sum = 0, msum = 0;

int main()
{
    cin >> n >> m >> t >> k;

    xs.resize(t);
    ys.resize(t);

    for(int i = 0;i<t;i++)
    {
        cin >> xs[i] >> ys[i];
    }

    for(int i = 0;i<t;i++)
    {
        for(int j = 0;j<t;j++)
        {
            int x, y;
            sum = 0;
            x = xs[i];
            y = ys[j];
            
            if(k + x >= n + 1)
                x = n - k;
            if(y - k < 0)
                y = 0 + k;

            for(int l = 0;l<t;l++)
            {
                if(x <= xs[l] && x + k >= xs[l] && y >= ys[l] && y - k <= ys[l])
                   sum++;

                if(sum > msum)
                {
                    ansx = x;
                    ansy = y;
                    msum = sum;
                }
            }
        }
    }

    cout << ansx << ' ' << ansy << '\n' << msum;

    return 0;
}