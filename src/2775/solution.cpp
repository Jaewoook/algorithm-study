#include <iostream>

using namespace std;

int main() {
    int T = 0, k = 0, n = 0, sum = 0, apt[15][15];
    cin >> T;


    for (int a = 0; a < T; a++) {
        cin >> k >> n;

        for (int i = 1; i <= n; i++) {
            apt[0][i] = i;
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                sum = 0;
                for (int m = 1; m <= j; m++) {
                    sum += apt[i - 1][m];
                }
                apt[i][j] = sum;
            }
        }
        cout << apt[k][n] << "\n";
    }

    return 0;
}
