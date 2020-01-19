#include <iostream>
using namespace std;

int main() {
    int N = 0, K = 0, count = 0, pos = 0, max = 0;
    cin >> N >> K;
    int *table = new int[N];

    for (int i = 0; i < N; i++) {
        table[i] = i + 1;
    }

    pos += (K - 1) % N;
    max = N;

    cout << "<";
    while (max > 0) {
        max = 0;
        count = 0;
        cout << table[pos];
        table[pos] = 0;

        for (int i = 0; i < N; i++) {
            if (max < table[i]) {
                max = table[i];
            }
        }

        if (max == 0) {
            break;
        }

        for (int i = 1; count <= K; i++) {
            count += table[(pos + i) % N] > 0 ? 1 : 0;
            if (count == K) {
                pos = (pos + i) % N;
                break;
            }
        }

        cout << ", ";
    }
    cout << ">\n";

    delete[] table;

    return 0;
}
