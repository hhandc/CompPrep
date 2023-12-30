#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, cnt = 0;
vector<int> diff;
vector<int> check;
vector<int> answer;

void che(int fir, int sec, int thi){
    int count = 0, ci = 0, rep;
    vector<int> c(1);
    c[0] = 0;
    c.push_back(fir);
    
    rep = c.size();
    for(int i = 0;i<rep;i++){
        c.push_back(c[i] + sec);
    }
    
    rep = c.size();
    for(int i = 0;i<rep;i++)
    {
        c.push_back(c[i] + thi);
    }
    
    sort(c.begin(), c.end());
    
    for(int i = 0;i<c.size();i++)
    {
        if(c[i] == check[ci])
        {
            count++;
            ci++;
        }
        
        if(ci == n)
            break;
    }
    
    if(count == n){
        cnt++;
    }
}

int main()
{
    cin >> t;
    
    answer.resize(t);
    for(int l = 0;l<t;l++)
    {
        cnt = 0;
        cin >> n;
        
        diff.resize(n);
        check.resize(n);
        
        for(int i = 0;i<n;i++)
        {
            cin >> diff[i];
            check[i] = diff[i];
        }
        
        sort(check.begin(), check.end());
        sort(diff.begin(), diff.end());
        
        for(int i = 0;i<n;i++)
        {
            for(int j = i + 1;j<n;j++)
            {
                diff.push_back(diff[j] - diff[i]);
            }
        }
        
        sort(diff.begin(), diff.end());
        
        int br = 0;
        
        for(int i = 0;i<diff.size();i++)
        {
            for(int j = i + 1;j<diff.size();j++)
            {
                if(diff[i] == diff[j])
                    diff[j] = -1;
            }
        }
            
        for(int i = 0;i<diff.size();i++)
        {
            for(int j = i;j<diff.size();j++)
            {
                for(int k = j;k<diff.size();k++)
                {
                    if(diff[i] > check[0])
                    {
                        br = 1;
                        break;
                    }
                    
                    if(diff[i] != -1 && diff[j] != -1 && diff[k] != -1) 
                        che(diff[i], diff[j], diff[k]);
                }
                
                if(br == 1)
                    break;
            }
            
            if(br == 1)
                break;
        }
        
        answer[l] = cnt;
    }
    
    for(int i = 0;i<t;i++)
    {
        cout << answer[i] << '\n';
    }
    
    return 0;
}
