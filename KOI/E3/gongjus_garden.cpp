#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


int main()
{
    int n;

    cin >> n;

    pair<int, int> flo[n];
    stack<pair<int, int> > mon;

    int sm, sd, em, ed;

    for(int i = 0;i<n;i++)
    {
        cin >> sm >> sd >> em >> ed;
        flo[i].first = sm * 100 + sd;
        flo[i].second = em * 100 + ed;
    }

    sort(flo, flo + n);

    mon.push(flo[0]);

    for(int i = 1;i<n;i++)
    {
        pair<int, int> comp = mon.top();

        if(comp.second < flo[i].second){
            if(comp.first <= 301 && flo[i].first <= 301)
            {
                mon.pop();
                mon.push(flo[i]);
            }
            else if(flo[i].first <= comp.first)
            {
                mon.pop();
                mon.push(make_pair(comp.second, flo[i].second));
            }
            else if(flo[i].first <= comp.second)
                mon.push(make_pair(comp.second, flo[i].second));
        }    
        
        if(mon.top().second >= 1130)
            break;
    }

    if(mon.top().second < 1130 || flo[0].first > 301)
        cout << "0";
    else
        cout << mon.size() << '\n';

    // int rep = mon.size();

    // for(int i = 0;i<rep;i++)
    // {
    //     cout << mon.top().first << ' ' << mon.top().second << '\n';
    //     mon.pop();
    // }

    return 0;
}