#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    bool is_prime = true;
    int M = 0, N = 0, root = 0, count = 0;

    cin >> M >> N;

    if (M == 1) {
        M = 2;
    }

    for (int i = M; i <= N; i++) {
        is_prime = true;
        root = sqrt(i);
        for (int k = 2; k <= root; k++) {
            if (i % k == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime == true) {
            cout << i << "\n";
            count++;
        }
    }

    return 0;
}
