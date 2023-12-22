#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int> > > color;
vector<int> counter;
vector<pair<pair<int, int>, pair<int, int> > > ball; 
vector<int> answer;

int main()
{
    int n, sum = 0, csum = 0;

    cin >> n;

    color.resize(n + 1);
    counter.resize(n);
    ball.resize(n);
    answer.resize(n);

    for(int i = 0;i<n;i++)
    {
        int a, b;

        cin >> a >> b;

        if(color[a].size() == 0)
            color[a].push_back(make_pair(0,0));

        color[a].push_back(make_pair(b, b));

        sum += b;

        ball[i].first.first = b;
        ball[i].second.first = a;
        ball[i].second.second = i;
    }

    csum = sum;
    sort(ball.begin(), ball.end());

    for(int i = 0;i<=n;i++)
    {
        if(color[i].size() > 0)
        {
            sort(color[i].begin(), color[i].end());

            for(int j = 1;j<color[i].size();j++)
            {
                color[i][j].second += color[i][j - 1].second;
            }
        }
    }

    for(int i = 0;i<=n;i++)
    {
        if(color[i].size() > 0)
        {
            for(int j = 1;j<color[i].size();j++)
            {
                if(j + 1 < color[i].size() && color[i][j].first == color[i][j + 1].first)
                {
                   color[i][j].second = color[i][j - 1].second;
                }
            }
        }
    }

    for(int i = 0;i<n;i++)
    {
        if(i - 1 >=0 && ball[i].first.first == ball[i - 1].first.first)
        {
            ball[i].first.second = ball[i - 1].first.second;
        }
        else
            ball[i].first.second = sum;

        sum -= ball[i].first.first;

        answer[ball[i].second.second] = csum - ball[i].first.second - color[ball[i].second.first][counter[ball[i].second.first]].second;
    
        counter[ball[i].second.first]++;
    }

    for(int i = 0;i<n;i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}