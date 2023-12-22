#include <iostream>
#include <vector>

using namespace std;

int t;
long long zcnt = 0, ocnt = 0;
vector<long long> one;
vector<long long> zero;

int main() {
    cin >> t;
    
    one.resize(41);
    zero.resize(41);
    
    one[0] = 0;
    one[1] = 1;
    zero[0] = 1;
    zero[1] = 0;
    
    for(int i = 2;i<=40;i++)
    {
        one[i] = one[i - 1] + one[i - 2];
        zero[i] = zero[i - 1] + zero[i - 2];
    }
    
    for(int i =0 ;i<t;i++)
    {
        int n;
        cin >> n;
        
        cout << zero[n] << ' ' << one[n] << '\n';
    }
    
    return 0;
}
