#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    cin >> N;

    int *A = new int[N];
    int *B = new int[N];
    int *P = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B, B + N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                B[j] = 0;
                P[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }

    delete[] A;
    delete[] B;
    delete[] P;
    return 0;
}
