#include <iostream>
#include <vector>

using namespace std;

vector<int> map;
vector<pair<int, int>> points;
pair<int, int> X;

int l ,w , n, gyung, sum = 0;

int main()
{
    cin >> w >> l >> n;

    map.resize(l * 2 + w * 2);

    for(int i = 0;i<n;i++)
    {
        int x, y;

        cin >> x >> y;

        if(x == 1)
        {
            map[w - y] = i + 1;
        }
        else if(x == 2)
        {
            map[w + l + y] = i + 1;
        }
        else if(x == 3)
        {
            map[w + y] = i + 1;
        }
        else if(x == 4)
        {
            map[w + l + w + l - y] = i + 1;
        }
    }

    cin >> X.first >> X.second;

    if(X.first == 1)
        gyung = w - X.second;
    else if(X.first == 2)
        gyung = w + l + X.second;
    else if(X.first == 3)
        gyung = w + X.second;
    else
        gyung = w + l + w + l - X.second;

    for(int i = 0;i<n;i++)
    {
        int left = gyung;
        int right = gyung;
        int lsum = 0;

        for(int j = 0;j<l*2+w*2;j++)
        {
            left--;
            right++;
            lsum++;
            
            if(left == -1)
                left = l * 2 + w * 2 - 1;
            
            if(right == l * 2 + w * 2 - 1)
                right = 0;
            
            if(map[left] == i + 1)
                break;
            
            if(map[right] == i + 1)
                break;
        }
        sum += lsum;
    }

    cout << sum;

    return 0;
}