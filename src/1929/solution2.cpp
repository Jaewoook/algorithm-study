#include <iostream>
using namespace std;

int main() {
    int M = 0, N = 0;

    cin >> M >> N;

    bool* num = new bool[N + 1];
    fill_n(num, N + 1, true);
    num[1] = false;

    for (int i = 2; i <= N; i++) {
        if (i * i >= 1000000) {
            break;
        }

        if (num[i] == true) {
            for (int j = i * i; j <= N; j += i) {
                num[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (num[i] == true) {
            cout << i << "\n";
        }
    }

    delete[] num;
    return 0;
}
