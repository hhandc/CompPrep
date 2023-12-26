#include <iostream>
#include <vector>

using namespace std;

int n, l, ma = 0;
vector<pair<int, int> > plate;

int main()
{
    cin >> n >> l;

    plate.resize(n);

    for(int i = 0;i<n;i++)
    {
       cin >> plate[i].first >> plate[i].second; 
       
       if(plate[i].second == 1){
            plate[i].first = l - plate[i].first;
       }
    }

    for(int i = 0;i<n - 1;i++)
    {
        if(plate[i].second == 0 && plate[i + 1].second == 1 && plate[i].first < plate[i + 1].first)
        {
            if(ma < (plate[i+1].first - plate[i].first) / 2)
                ma = (plate[i+1].first - plate[i].first) / 2;
        }        
        else if(plate[i].second == 1 && plate[i + 1].second == 0 && plate[i + 1].first < plate[i].first)
        {
            if(ma < (plate[i].first - plate[i + 1].first) / 2)
                ma = (plate[i].first - plate[i + 1].first) / 2;
        }
    }

    cout << ma;

    return 0;
}