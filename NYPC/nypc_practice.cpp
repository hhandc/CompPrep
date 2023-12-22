#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt;
vector<string> nused;
vector<string> used;
vector<int> check;

int main()
{
    cin >> n >> k;
    
    cnt = k;
    
    nused.resize(n);
    used.resize(k);
    check.resize(k);
    
    for(int i = 0;i<n;i++)
    {
        cin >> nused[i];
    }
    
    for(int i = 0;i<k;i++)
    {
        cin >> used[i];
    }
    
    for(int i = 0;i<k;i++)
    {
        for(int j = i + 1;j<k;j++)
        {
            if(used[i] == used[j] && check[i] == 0 && check[j] == 0){
                cnt--;
                check[i] = 1;
                check[j] = 1;
            }   
        }
    }
    
    cout << cnt;
    
    return 0;
}