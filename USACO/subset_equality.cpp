#include <iostream>
#include <vector>

using namespace std;

int q;
string s;
string t;
string ans;
string qq;
vector<vector<int>> wrong(18, vector<int>(18));

int search(int x, int y){
    string fi;
    string se;
    
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] - 97 == x || s[i] - 97 == y)
            fi.push_back(s[i]);
    }
    
    for(int i = 0;i<t.length();i++)
    {
        if(t[i] - 97 == x || t[i] - 97 == y)
            se.push_back(t[i]);
    }
    
    if(fi.length() != se.length())
        return -1;
    else{
        for(int i = 0;i<fi.length();i++)
        {
            if(fi[i] != se[i])
                return -1;
        }
        
        return 0;
    }
}

int main()
{
    cin >> s >> t;
    cin >> q;
    
    vector<int> salphabet(18);
    vector<int> talphabet(18);
    
    for(int i = 0;i<s.length();i++)
    {
        salphabet[s[i] - 97] = 1;
    }
    
    for(int i = 0;i<t.length();i++)
    {
        talphabet[t[i] - 97] = 1;
    }
    
    for(int i = 0;i<18;i++)
    {
        for(int j = 0;j<18;j++)
        {
            wrong[i][j] = 1;
        }
    }
    
    for(int i = 0;i<18;i++)
    {
        for(int j = i;j<18;j++)
        {
            if(salphabet[i] == 1 && talphabet[j] == 1){
                int yn = search(i, j);
                
                if(yn == -1){
                    wrong[i][j] = -1;
                }
                else
                    wrong[i][j] = 0;
            }
        }
    }
    
    for(int i = 0;i<q;i++)
    {
        cin >> qq;
        
        int answer = 0;
        for(int i = 0;i<qq.size();i++)
        {
            for(int j = i;j<qq.size();j++)
            {
                if(wrong[qq[i] - 97][qq[j] - 97] == -1 || wrong[qq[i] - 97][qq[j] - 97] == 1)
                    answer = -1;
            }
        }
        
        if(answer == -1)
            ans.push_back('N');
        else
            ans.push_back('Y');
    }
    
    cout << ans;
    return 0;
}
