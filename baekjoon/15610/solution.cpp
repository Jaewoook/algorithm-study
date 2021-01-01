#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned long long size;
    cin >> size;

    cout << fixed;
    cout.precision(6);
    cout << sqrt(size) * 4 << "\n";
    return 0;
}
