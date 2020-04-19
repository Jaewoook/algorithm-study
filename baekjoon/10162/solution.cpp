#include <iostream>
using namespace std;

#define BTN_A 300
#define BTN_B 60
#define BTN_C 10

int main() {
    int T = 0, A = 0, B = 0, C = 0;
    cin >> T;

    if (T % 10 > 0) {
        cout << -1 << "\n";
    } else {
        while (T > 0) {
            A = T / BTN_A;
            T -= A * BTN_A;

            B = T / BTN_B;
            T -= B * BTN_B;

            C = T / BTN_C;
            T -= C * BTN_C;
        }

        cout << A << " " << B << " " << C << "\n";
    }

    return 0;
}
