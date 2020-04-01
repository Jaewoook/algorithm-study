#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B;

    cin >> A >> B;

    for (int i = 2; i >= 0; i--) {
        if (A[i] - 48 > B[i] - 48) {
            cout << A[2] << A[1] << A[0];
            break;
        } else if (A[i] - 48 < B[i] - 48) {
            cout << B[2] << B[1] << B[0];
            break;
        }
    }

    return 0;
}
