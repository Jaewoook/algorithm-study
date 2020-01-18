#include <iostream>

using namespace std;

int main() {
    int N = 0, a = 1, b = 1, tmp = 0;

    cin >> N;

    for (int i = 2; i <= N; i++ ) {
        tmp = b;
        b += a;
        a = tmp;
        b %= 15746;
    }

    cout << b << "\n";

    return 0;
}
