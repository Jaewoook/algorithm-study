#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N = 0, count = 0, size = 123456 * 2 + 1;
    bool num[123456 * 2 + 1] = { false, };
    fill_n(num, size, true);

    for (int i = 2; i <= size; i++) {
        if (i * i >= size) {
            break;
        }

        if (num[i] == true) {
            for (int j = i * i; j <= size; j += i) {
                num[j] = false;
            }
        }
    }

    while (true) {
        count = 0;
        cin >> N;

        if (N == 0) {
            break;
        }

        for (int i = N + 1; i <= 2 * N; i++) {
            if (num[i] == true) {
                count++;
            }
        }

        cout << count << "\n";
    }
    return 0;
}
