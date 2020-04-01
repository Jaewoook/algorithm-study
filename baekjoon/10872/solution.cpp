#include <iostream>

using namespace std;

int main() {
    int N = 0, total = 1;
    cin >> N;

    for (int i = N; i > 0; i--) {
        total *= i;
    }

    cout << total << "\n";
    return 0;
}
