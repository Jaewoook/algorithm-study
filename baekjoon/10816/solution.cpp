#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, key = 0, start_i = 0, end_i = 0, result = 0;

    cin >> N;
    int *num = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> key;
        start_i = lower_bound(num, num + N, key) - num;
        end_i = upper_bound(num, num + N, key) - num;

        result = end_i - start_i;
        cout << result << (M - 1 == i ? "\n" : " ");
    }

    delete[] num;
    return 0;
}
