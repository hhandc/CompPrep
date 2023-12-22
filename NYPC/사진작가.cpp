#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, cnt = 0, ma = 0;
map<int,int> m;
vector<int> color;

int main()
{
    cin >> n;

    color.resize(n);

    for(int i = 0;i<n;i++)
    {
        cin >> color[i];
    }

    for(int i = 0;i<n;i++)
    {
        if(m.find(color[i]) == m.end()){
            m.insert({color[i], i});
            cnt++;
        }
        else{
            auto a = m.find(color[i]);
            
            i = a->second;
            
            cnt = 0;
            m.clear();
        }
        
        if(cnt > ma)
            ma = cnt;
    }

    cout << ma;

    return 0;
}