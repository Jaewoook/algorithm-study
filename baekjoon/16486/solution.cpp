#include <iostream>
using namespace std;

int main() {
    long double d1 = 0, d2 = 0;
    cin >> d1 >> d2;

    cout << fixed;
    cout.precision(6);
    cout << 3.141592 * d2 * 2 + d1 * 2 << "\n";
    return 0;
}
