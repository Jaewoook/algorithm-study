#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x = 0, y = 0, w = 0, h = 0;
    cin >> x >> y >> w >> h;

    cout << min(min(x, w - x), min(y, h - y)) << "\n";
    return 0;
}
