#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, B, C;
    cin >> N;
    long long result = 0;
    int *a = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> B >> C;

    while (N--) {
        result++;
        a[N] -= B;
        if (a[N] <= 0) continue;
        result += ceil((double) a[N] / C);
    }
    cout << result << "\n";

    delete[] a;
    return 0;
}
