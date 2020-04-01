#include <iostream>
using namespace std;

int main() {
    int N = 0, F = 0;
    cin >> N >> F;

    N /= 100;
    for (int i = 0; i < 100; i++) {
        if ((N * 100 + i) % F == 0) {
            F = i;
            break;
        }
    }

    cout << (F < 10 ? "0" : "") << F << "\n";

    return 0;
}
