#include <iostream>
using namespace std;

int main() {
    int H = 0, M = 0, min = 0;

    cin >> H >> M >> min;
    H += min / 60;
    M += min % 60;
    if (M >= 60) {
        H++;
        M %= 60;
    }
    H %= 24;

    cout << H << " " << M;

    return 0;
}
