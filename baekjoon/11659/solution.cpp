#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int *num = new int[N];
    int *sum = new int[N + 1];
    sum[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        sum[i + 1] = num[i] + sum[i];
    }

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << "\n";
    }

    delete[] num;
    delete[] sum;
    return 0;
}
