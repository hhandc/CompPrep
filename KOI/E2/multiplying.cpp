#include <iostream>
#include <vector>

using namespace std;

int a, b;
long long product;

int main()
{
    cin >> a >> b;

    product = a * b;

    cout << (b % 10) * a << '\n';
    b /= 10;
    cout << (b % 10) * a << '\n';
    b /= 10;
    cout << b * a << '\n';
    cout << product;

    return 0;
}
