#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N = 0, time = 0, wait = 0;
    cin >> N;

    int *P = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    for (int i = 0; i < N; i++) {
        wait = 0;
        for (int j = 0; j <= i; j++) {
            wait += P[j];
        }
        time += wait;
    }

    cout << time << "\n";

    delete[] P;
    return 0;
}
