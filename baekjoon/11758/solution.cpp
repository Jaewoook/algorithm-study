#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int result = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    cout << (result == 0 ? 0 : result > 0 ? 1 : -1) << "\n";
    return 0;
}
