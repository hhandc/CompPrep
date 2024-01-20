#include <iostream>
#include <vector>

using namespace std;

vector<int> rocks;
vector<vector<long long> > F;
vector<vector<int> > Z;
vector<long long> S;

int main()
{
    int n;

    cin >> n;

    rocks.resize(n + 1);
    F.resize(n + 1, vector<long long>(n + 1));
    Z.resize(n + 1);
    S.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> rocks[i];
    }

    for (int i = 1; i <= n; i++)
    {
        F[i][i] = rocks[i];
        for (int j = i + 1; j <= n; j++)
        {
            F[i][j] = rocks[j] - F[i][j - 1];
            
            if(F[i][j]<0) break;

            if (F[i][j] == 0)
                Z[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        S[i] = S[i - 1] + 1;

        if (Z[i].size() > 0)
        {
            for (int j = 0; j < Z[i].size(); j++)
            {
                if (S[Z[i][j] - 1] + i - Z[i][j] < S[i])
                    S[i] = S[Z[i][j] - 1] + i - Z[i][j];
            }
        }
    }

    cout << S[n];

    return 0;
}