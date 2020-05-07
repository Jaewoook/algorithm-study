#include <iostream>
using namespace std;

int main() {
    int n = 0, m = 0, a = 0, na = 0, ma = 0;
    cin >> n >> m >> a;

    if (n <= a) {
        na = 1;
    } else if (n % a > 0) {
        n += n % a;
        na = n / a;
    }
    if (m <= a) {
        ma = 1;
    } else if (m % a > 0) {
        m += m % a;
        ma = m / a;
    }

    cout << na * ma << "\n";

    return 0;
}
