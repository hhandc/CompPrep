#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K;
    cin >> K;

    pair<int, int> v[6];

    int startIndex, maxW = 0, maxH = 0;
    int dir, len;
    for(int i = 0; i < 6; i++){
        cin >> dir >> len;
        v[i].first = dir;
        v[i].second = len;

        if (dir == 1 || dir == 2) {
            if (maxW < len) {
                maxW = len;
                startIndex = i;
            }
        }
        if (dir == 3 || dir == 4) {
            if (maxH < len) {
                maxH = len;
            }
        }
    }

    int ans1 = -1, ans2 = -1;

    for(int i = 0; i < 6; i++) {
        if(v[(startIndex + i) % 6].first == v[(startIndex + i + 2) % 6].first) {
            if (ans1 < 0)
                ans1 = v[(startIndex + i + 2) % 6].second;
            else
                ans2 = v[(startIndex + i) % 6].second;
        }
    }

    cout << ((maxW * maxH) - (ans1 * ans2)) * K;

    return 0;
}