#include <iostream>
#include <vector>

using namespace std;

vector<int> paper(7);

int main()
{
    int cnt = 0;

    for(int i = 0;i<6;i++)
    {
        cin >> paper[i + 1];
    }

    for(int i = 6;i>=1;i--)
    {
        if(i == 6)
            cnt += paper[i];
        else if(i == 5)
        {
            cnt += paper[i];
            paper[1] -= paper[i] * 11;
        }
        else if(i == 4)
        {
            int c = paper[i] * 5;
            cnt += paper[i];

            if(paper[2] >= c)
                paper[2] -= c;
            else
            {
                c -= paper[2];
                paper[2] = 0;
                c *= 4;

                paper[1] -= c;
            }
        }
        else if(i == 3)
        {
            cnt += paper[i] / 4;
            int c = paper[i] % 4;

            if(c > 0)
                cnt++;

            if(c == 3)
            {
                if(paper[2] > 0)
                {
                    paper[2]--;
                    paper[1] -= 5;
                }
                else
                    paper[1] -= 9;
            }
            if(c == 2)
            {
                    if(paper[2] >= 3)
                    {
                        paper[2] -= 3;
                        paper[1] -= 6;
                    }
                    else{
                        paper[1] -= (3 - paper[2]) * 4 + 6;
                        paper[2] = 0;
                    }
            }
            if(c == 1)
            {
                    if(paper[2] >= 5)
                    {
                        paper[2] -= 5;
                        paper[1] -= 7;
                    }
                    else{
                        int b = (5 - paper[2]) * 4 + 7;
                        paper[2] = 0;
                        paper[1] -= b;
                    }
            }
        }
        else if(i == 2)
        {
                cnt += paper[i] / 9;
                int c = paper[i] % 9;

                if(c > 0)
                {
                    cnt++;
                    c = 36 - c * 4;

                    paper[1] -= c;
                }
        }
        else if(i == 1){
            if(paper[1] > 0)
            {
                cnt += paper[i] / 36;
                int c = paper[i] % 36;
                if(c > 0)
                    cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}