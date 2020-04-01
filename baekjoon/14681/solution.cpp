#include <iostream>
using namespace std;

int main() {
    int x = 0, y = 0, area = 0;
    cin >> x >> y;

    if (x > 0) {
        area  = y > 0 ? 1 : 4;
    } else {
        area  = y > 0 ? 2 : 3;
    }

    cout << area << "\n";
    return 0;
}
