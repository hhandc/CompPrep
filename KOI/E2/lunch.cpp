#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> seat;
vector<int> take;

int main()
{
    cin >> n;
    seat.resize(n);
    take.resize(n);

    for(int i = 0;i<n;i++)
    {
        cin >> take[i];
    }

    for(int i = 0;i<n;i++)
    {
        if(seat[i - take[i]] == 0)
            seat[i - take[i]] = i + 1;
        else{
            int temp = seat[i - take[i]];

            for(int j = i - take[i] + 1;j<n;j++)
            {
                int temp2 = seat[j];
                seat[j] = temp;
                temp = temp2;
            }

            seat[i - take[i]] = i + 1; 
        }
    }

    for(int i = 0;i<n;i++)
    {
        cout << seat[i] << ' ';
    }
    
    return 0;
}
