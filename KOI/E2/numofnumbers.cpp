#include <iostream>
#include <vector>

using namespace std;

int a, b, c;
long long product;
vector<int> cnt;

int main()
{
    cin >> a >> b >> c;

    product = a * b * c;

    cnt.resize(10);

    while(1)
    {
        cnt[product % 10]++;
        product /= 10;

        if(product == 0)
            break;
    }

    for(int i = 0;i<10;i++)
    {
        cout << cnt[i] << '\n';
    }

    return 0;
}
