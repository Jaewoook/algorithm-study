#include <iostream>
using namespace std;

int main() {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    int x = 0, y = 0;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    x = x1 + x2 + x3;
    if (x1 == x2 || x1 == x3) {
      x -= x1 * 2;
    } else if (x2 == x3) {
      x -= x2 * 2;
    }

    y = y1 + y2 + y3;
    if (y1 == y2 || y1 == y3) {
      y -= y1 * 2;
    } else if (y2 == y3) {
      y -= y2 * 2;
    }

    cout << x << " " << y << "\n";

    return 0;
}
