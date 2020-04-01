#include <iostream>
using namespace std;

int main() {
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n = 0, i = 2;
    cin >> n;

    while (n > 1) {
        if (n % i == 0) {
            n /= i;
            cout << i << "\n";
        } else {
            i++;
        }
    }

    return 0;
}
