#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long N = 0, c = 0, result = 0;
    cin >> N;
    vector<int> f(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> f[i];
    }
    cin >> c;

    for (int i = 0; i < N; i++) {
        result += f[i] % c > 0 ? f[i] - (f[i] % c) + c : f[i];
    }

    cout << result << "\n";

    return 0;
}
