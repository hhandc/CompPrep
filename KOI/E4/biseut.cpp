#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> alph(26);
vector<int> v(26);

int ans = 0;

int main()
{
    int n;

    cin >> n;

    string comp;
    string s;

    cin >> comp;

    for(int i = 0;i<comp.size();i++)
        alph[comp[i] - 'A']++;

    for(int i= 0;i<n - 1;i++)
    {
        int b = 0, chance = 0;
        v.clear();
        v.resize(26);
        cin >> s;

        for(int j=0;j<s.size();j++)
                v[s[j] - 'A']++;

        if(s.size() >= comp.size() - 1 && s.size() <= comp.size() + 1)
        {
            for(int j = 0;j<26;j++)
            {
                if(v[j] != alph[j])
                    chance += abs(v[j] - alph[j]);
            }

            if(chance <= 2)
                ans++;
        }
    }

    cout << ans;

    return 0;
}