#include <iostream>
#include <vector>

using namespace std;

string s;

int main()
{
    cin >> s;

    int cnt = 0, sum = 0;

    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == '(' && s[i + 1] == ')')
        {
            sum += cnt;
        }   
        else if(s[i] == '(' && s[i + 1] =='(')
            cnt++;
        else if(s[i] == ')' &&  s[i - 1] != '(')
        {
            sum += 1;
            cnt--;
        }
    }

    cout << sum;

    return 0;
}