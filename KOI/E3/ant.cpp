#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int w, h, p, q;
long long t;

int main()
{
    cin >> w >>h >> p >> q >> t;
    
    int tw, th;
    
    tw = t % (2 * w);
    th = t % (2 * h);
    
    if(p + tw > w)
    {
        p += tw - 2 * w;
        if(p > w)
            p -= w;
    }
    else
        p += tw;
        
    if(q + th > h)
    {
        q += th - 2 * h;
        if(q > h)
            q -= h;
    }
    else
        q += th;  
        
    cout << abs(p) << ' ' << abs(q);
    
    return 0;
}