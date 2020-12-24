#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    int **num = new int*[N + 1];
    int **sum = new int*[N + 1];
    for (int i = 0; i <= N; i++) {
        num[i] = new int[N + 1];
        sum[i] = new int[N + 1];
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0) {
                num[i][j] = 0;
            }
            if (j == 0) {
                num[i][j] = 0;
            }
            if (i > 0 && j > 0) {
                cin >> num[i][j];
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + num[i][j];
            }
        }
    }

    int x1, x2, y1, y2, result;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        result = 0;
        result = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
        cout << result << "\n";
    }

    for (int i = 0; i <= N; i++) {
        delete[] num[i];
        delete[] sum[i];
    }
    delete[] num;
    delete[] sum;
    return 0;
}
