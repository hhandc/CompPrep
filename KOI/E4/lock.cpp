#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> nxt;
vector<pair<int, int> > flip;

int main()
{
    int n, check = 0, fpush = 0, spush, f, s, comp;

    cin >> n;
    v.resize(n);
    nxt.resize(n + 1);

    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
        
        if(i == n - 1)
            nxt[i + 1] = 1;
        else
            nxt[i + 1] = i + 2;
    }

    for(int i =0;i<n;i++)
    {
        if(v[i] == n - i)
            comp = 1;
        else{
            comp = 0;
            break;
        }
    }

    if(comp == 1)
        cout << "1" << '\n' << "1 " << n << '\n' << "1";
    else
    {
        for(int i = n - 1;i>=0;i--)
        {
            if(i - 1 >= 0 && v[i - 1] == nxt[v[i]])
                flip.push_back(make_pair(i, v[i]));
            else if(v[i] == nxt[v[i + 1]])
                flip.push_back(make_pair(i, v[i]));

            if(i == 0)
            {
                if(v[v.size() - 1] == nxt[v[i]]){
                    flip.push_back(make_pair(v.size() - 1, v[v.size() - 1]));
                    flip.push_back(make_pair(i, v[i]));
                }
            }
        }

        sort(flip.begin(), flip.end());

        for(int i = 0;i<flip.size() - 1;i++)
        {
            if(flip[i].first != flip[i + 1].first - 1)
            {
                check = flip[i + 1].first;
                break;
            }
        }

        if(check != 0)
            fpush = n - check;
        else
        {
            if(flip[flip.size() - 1].first == n - 1)
                fpush = flip.size();
            else
                fpush = n - flip[flip.size() - 1].first - 1;
        }

        for(int i = 0;i<fpush;i++)
        {
            v.insert(v.begin(), v[v.size() - 1]);
            v.pop_back();
        }
        
        for(int i = 0;i<n;i++)
        {
            cout << v[i] << ' ';
        }

        cout << '\n';

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<flip.size();j++)
            {
                if(v[i] == flip[j].second)
                {
                    flip[j].first = i;
                }
            }
        }

        sort(flip.begin(), flip.end());

        f = flip[0].first;
        s = flip[flip.size() - 1].first;

        for(int i = 0;i<flip.size();i++)
        {
            v[flip[i].first] = flip[flip.size() - i - 1].second;
        }
        
        for(int i = 0;i<flip.size();i++)
        {
            cout << flip[i].first << ' ' << flip[i].second << '\n';
        }
        
        for(int i = 0;i<n;i++)
        {
            if(v[i] == 1)
                spush = n - i;
            
        }

        for(int i = 0;i<spush;i++)
        {
            v.insert(v.begin(), v[v.size() - 1]);
            v.pop_back();
        }

        for(int i = 0;i<n;i++)
        {
            cout << v[i] << ' ';
        }

        cout << '\n';
        cout << spush << '\n' << f + 1 << ' ' << s + 1 << '\n' << fpush;
    }
    return 0;
}