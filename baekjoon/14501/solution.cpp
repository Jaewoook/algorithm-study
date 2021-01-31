#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, T, P;
    cin >> N;
    pair<int, int> *s = new pair<int, int>[N + 1];
    int *result = new int[N + 1];
    fill_n(result, N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> T >> P;
        s[i] = make_pair(T, P);
    }

    for (int i = 1; i <= N; i++) {
        int e = i + s[i].first - 1;
        if (e <= N && result[e] < result[i - 1] + s[i].second) {
            for (int j = e; j <= N; j++) {
                if (result[j] > result[i - 1] + s[i].second) {
                    break;
                }
                result[j] = result[i - 1] + s[i].second;
            }
        }
    }

    cout << result[N] << "\n";

    delete[] s;
    delete[] result;
    return 0;
}
