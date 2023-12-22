#include <iostream>
#include <vector>

using namespace std;

int a, b, c, n, vmax = -1, cnt = 0;

vector<vector<int>> student;

int comp(int f, int s, int t)
{
    if(f > s && f > t)
        return 1;
    else if(s > f && s > t)
        return 2;
    else if(t > s && t > f)
        return 3;
    else
        return 0;
}

int main()
{
    cin >> n;

    student.resize(4, vector<int>(4));

    for(int i =0 ;i<n;i++)
    {
        cin >> a>> b >> c;

        student[1][0] += a;
        student[2][0] += b;
        student[3][0] += c;

        student[1][a]++;
        student[2][b]++;
        student[3][c]++;
    }

    for(int i = 0;i<3;i++)
    {            
        if(student[i][0] > vmax)
            vmax = student[i][0];        
    }

    for(int i = 0;i<3;i++)
    {
        if(student[i][0] == vmax)
        {
            student[i][0] = 1;
            cnt++;
        }
    }

    if(cnt == 1)
    {
        if(student[1][0] == 1)
            cout << "1" << ' ' << vmax;
        else if(student[2][0] == 1)
            cout << "2" << ' ' << vmax;
        else if(student[3][0] == 1)
            cout << "3" << ' ' << vmax;
    }
    else if (cnt == 2)
    {
        if(student[1][0] == 1 && student[2][0] == 1)
        {
            int res = comp(student[1][1], student[2][1], 0);

            if(res == 0)
            {
                res = comp(student[1][2], student[2][2], 0);

                cout << res << ' ' << vmax;
            }
            else
                cout << res << ' ' << vmax;
        }
        else if(student[2][0] == 1 && student[3][0] == 1)
        {
            int res = comp(0, student[2][1], student[3][1]);

            if(res == 0)
            {
                res = comp(0, student[2][2], student[3][2]);

                cout << res << ' ' << vmax;
            }
            else
                cout << res << ' ' << vmax;
        }
        else if(student[1][0] == 1 && student[3][0] == 1)
        {
            int res = comp(student[1][1], 0, student[3][1]);

            if(res == 0)
            {
                res = comp(student[1][2], 0, student[3][2]);

                cout << res << ' ' << vmax;
            }
            else
                cout << res << ' ' << vmax; 
        }
    }
    else{
        int res = comp(student[1][1], student[2][1], student[3][1]);

        if(res == 0)
        {
            res = comp(student[1][2], student[2][2], student[3][2]);

            cout << res << ' ' << vmax;
        }
        else 
            cout << res << ' ' << vmax;
    }

    return 0;
}
