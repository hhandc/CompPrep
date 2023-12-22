#include <iostream>
#include <vector>

using namespace std;

int n, last, ansa = 0,ansb = 0;

void check(int b, int c, int cnt)
{
    int a = c - b;

    if(a > b)
        return;
    else 
        check(a, b, cnt+1);
    
    if(cnt == n - 2)
    {
        ansa = a;
        ansb = b;
        return;
    }
}

int main()
{
    cin >> n >> last;
    
    int a, b, c;
    
    c = last;
    b = last / 2 + 1;
    
    for(int i = b;i<=c-1;i++)
    {
        if(ansa != 0 && ansb != 0)
            break;
        
        check(i, c, 1);
    }

    cout << ansa << '\n' << ansb;
}
