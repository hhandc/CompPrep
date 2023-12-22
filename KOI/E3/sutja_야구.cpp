#include <iostream>
#include <vector>

using namespace std;

int gn, s, b, n, ans = 0;
vector<vector<int>> guess;

int main()
{
    cin >> n;

    guess.resize(n, vector<int>(5));

    for(int i = 0;i<n;i++)
    {
        cin >> gn >> s >> b;

        guess[i][0] = gn / 100;
        guess[i][1] = gn % 100 / 10;
        guess[i][2] = gn % 100 % 10;
        guess[i][3] = s;
        guess[i][4] = b;
    }

    for(int i = 1;i<=9;i++)
    {
        for(int j = 1;j<=9;j++)
        {
            for(int k = 1;k<=9;k++)
            {
                int correct = 0, strike = 0, ball = 0;
                if(i != j && j != k && k != i)
                {
                    for(int l= 0;l<n;l++)
                    {
                        strike = 0;
                        ball = 0;

                        if(guess[l][0] == i)
                            strike++;
                        else if(guess[l][1] == i || guess[l][2] == i)
                            ball++;

                        if(guess[l][1] == j)
                            strike++;
                        else if(guess[l][0] == j || guess[l][2] == j)
                            ball++;

                        if(guess[l][2] == k)
                            strike++;
                        else if(guess[l][0] == k || guess[l][1] == k)
                            ball++;
                        
                        if(strike == guess[l][3] && ball == guess[l][4])
                            correct++;
                        else
                            break;
                    }
                }

                if(correct == n){
                    ans++;
                    cout << (i * 100 + j * 10 + k) << '\n';
                }
            }
        }
    }

    cout << ans;

    return 0;
}