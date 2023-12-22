#include <iostream>
#include <vector>

using namespace std;

int n, p, cnt = 0, tempn;

vector<int> other;

int main()
{
    cin >> n >> p;

    other.resize(p + 1);
    
    tempn = n;
    
    while(1)
    {
        cnt++;

        tempn *= n;

        tempn %= p;

        if(other[tempn] == 0)
            other[tempn] = cnt;
        else
        {
            cout << cnt - other[tempn];
            break;
        }
    }

    return 0;
}