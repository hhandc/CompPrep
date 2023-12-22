#include <iostream>
#include <vector>

using namespace std;

int c, r, x = 1, y = 0, constc, constr;
bool add = true;
long long k;
long long sum = 0;

int main()
{
    cin >> c >> r >> k;
    
    constc = c;
    constr = r;
    while(1)
    {
        if(k > constc * constr)
        {
            cout << "0";
            break;
        }
        
        sum += r;

        if(add == true)
        {
            y += r;

            if(sum > k){
                y -= sum - k;
                cout << x << ' ' << y;
                break;
            }
            else if(sum == k){
                cout << x << ' ' << y;
                break;
            }
        }
        else
        {
            y -= r;

            if(sum > k){
                y += sum - k;
                cout << x << ' ' << y;
                break;
            }
            else if(sum == k){
                cout << x << ' ' << y;
                break;
            }
        }

        r--;
        c--;

        sum += c;

        if(add == true)
        {
            x += c;

            if(sum > k){
                x -= sum - k;
                cout << x << ' ' << y;
                break;
            }
            else if(sum == k){
                cout << x << ' ' << y;
                break;
            }

            add = false;
        }
        else
        {
            x -= c;

            if(sum > k){
                x += sum - k;
                cout << x << ' ' << y;
                break;
            }
            else if(sum == k){
                cout << x << ' ' << y;
                break;
            }

            add = true;
        }
    }

    return 0;
}