#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> placement;
vector<int> numb;
vector<int> out;

int main()
{
    cin >> n;

    placement.resize(n);
    numb.resize(n);
    out.resize(n);

    for(int i = 0;i<n;i++)
    {
        cin >> placement[i].first >> placement[i].second;
        numb[i] = i;
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = i;j<n;j++)
        {
            if(placement[i].first > placement[j].first && placement[i].second > placement[j].second)
            {
                int tempf = placement[i].first;
                int temps = placement[i].second;

                placement[i].first = placement[j].first;
                placement[i].second = placement[j].second;

                placement[j].first = tempf;
                placement[j].second = temps;

                tempf = numb[i];
                numb[i] = numb[j];
                numb[j] = tempf;
            }   
        }
    }
    
    for(int i = 0;i<n;i++)
    {
        int start, cnt = 1;

        for(int j = 0;j<n;j++)
        {
            if(numb[j] == i)
            {
                start = j;
                break;
            }
        }

        for(int j = start;j<n;j++)
        {
            if(placement[start].first < placement[j].first && placement[start].second < placement[j].second)
                cnt++;
        }

        out[i] = cnt;
    }

    for(int i = 0;i<n;i++)
    {
        cout << out[i] << ' ';
    }
    return 0;
}