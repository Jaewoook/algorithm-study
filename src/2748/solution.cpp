#include <iostream>

using namespace std;

int main() {
    long long N = 0, a = 0, b = 1, tmp = 0;

    cin >> N;

    for (int i = 2; i <= N; i++ ) {
        tmp = b;
        b += a;
        a = tmp;
    }

    if (N < 1) {
        b = 0;
    }

    cout << b << "\n";

    return 0;
}
