#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string s;
stack<int> st;

void check(){    
    if(st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();

        if(b > 0)
        {
            st.pop();
            b += a;
            st.push(b);
        }
        else
        {
            st.push(a);
        } 
    }
    
    return;
}

int main()
{
    int ans, wrong = 0;
    cin >> s;

    if(s[0] != '(' && s[0] != '[')
        wrong = 1;
    else{
        if(s[0] == '(')
            st.push(-1);
        else if(s[0] == '[')
            st.push(0);

        for(int i= 1;i<s.size();i++)
        {
            int comp = st.top();

            if(s[i] == '(')
                st.push(-1);
            else if(s[i] == '[')
                st.push(0);
            else if(s[i] == ')')
            {
                if(comp == -1)
                {
                    st.pop();
                    st.push(2);
                    check();
                }
                else if(comp > 0)
                {
                    st.pop();
                    if(st.size() > 0 && st.top() == -1)
                    {
                        st.pop();
                        st.push(comp * 2);
                        check();
                    }
                    else 
                    {
                        wrong = 1;
                        break;
                    }
                }
                else
                {
                    wrong = 1;
                    break;
                }
            }
            else if(s[i] == ']')
            {
                if(comp == 0)
                {
                    st.pop();
                    st.push(3);
                    check();
                }
                else if(comp > 0){
                    st.pop();
                    if(st.size() > 0 && st.top() == 0)
                    {
                        st.pop();
                        st.push(comp * 3);
                        check();
                    }
                    else{
                        wrong = 1;
                        break;
                    }
                }
                else
                {
                    wrong = 1;
                    break;
                }
            }
        }
    }

    if(st.size() > 0)
    {
        ans = st.top();
        st.pop();
    }
    
    if(st.empty() != true || wrong == 1 || ans == -1 || ans == 0)
        cout << 0;
    else
        cout << ans;

    return 0;
}