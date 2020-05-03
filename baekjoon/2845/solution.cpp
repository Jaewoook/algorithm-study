#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int L = 0, P = 0, n = 0;
    cin >> L >> P;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        cout << n - L * P << " ";
    }
    return 0;
}
