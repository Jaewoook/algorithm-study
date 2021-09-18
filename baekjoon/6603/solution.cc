#include <iostream>
#include <algorithm>
using namespace std;

void combination(int *S, int *C, int k, int r, int depth) {
    if (r == 0) {
        for (int i = 0; i < 6; i++) {
            cout << C[i] << " ";
        }
        cout << "\n";
    } else if (depth == k) {
        return;
    } else {
        C[6 - r] = S[depth];
        combination(S, C, k, r - 1, depth + 1);

        combination(S, C, k, r, depth + 1);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int k, S[13], C[13];
    while(1) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) {
            cin >> S[i];
        }

        combination(S, C, k, 6, 0);
        cout << "\n";
    }
    return 0;
}
