#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sum = 0, ldia = 0, rdia= 0, lcheck =0, rcheck = 0;
    vector<vector<int>> bingo(6, vector<int>(6));
    vector<int> call(25);
    vector<int> hor(6);
    vector<int> ver(6);

    for(int i = 1;i<=5;i++)
    {
        for(int j = 1;j<=5;j++)
        {
            cin >> bingo[i][j];
        }
    }

    for(int i = 0;i<25;i++)
    {
        cin >> call[i];
    }
    
    for(int i = 0;i<25;i++)
    {
        for(int j = 1;j<=5;j++)
        {
            for(int k = 1;k<=5;k++)
            {
                if(bingo[j][k] == call[i])
                {
                    hor[k]++;
                    ver[j]++;

                    if(j == k)
                        ldia++;
                    if(6 - k == j)
                        rdia++;
                    
                    if(hor[k] == 5)
                        sum++;
                    if(ver[j] == 5)
                        sum++;

                    if(ldia == 5 && lcheck == 0)
                    {
                        sum++;
                        lcheck = 1;
                    }
                    
                    if(rdia == 5 && rcheck == 0)
                    {
                        sum++;
                        rcheck = 1;
                    }
                    
                    if(sum >= 3)
                    {
                        cout << i + 1;
                        break;
                    }
                }
            }
            if(sum >= 3)
                break;
        }
        
        if(sum >= 3)
            break;
    }

    return 0;
}