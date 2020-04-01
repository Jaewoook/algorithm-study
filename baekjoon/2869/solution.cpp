#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, v = 0;
    cin >> a >> b >> v;

    cout << (v - b - 1) / (a - b) + 1 << "\n";

    return 0;
}
