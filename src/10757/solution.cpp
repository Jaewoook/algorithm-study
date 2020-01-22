#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    string A, B, result = "";
    int tmp = 0, up = 0, n_size = 0, m_size = 0, length = 0;
    cin >> A >> B;
    n_size = A.size();
    m_size = B.size();
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    length = max(m_size, n_size);

    for (int i = 0; i < length; i++) {
        tmp = up;
        if (n_size > i) {
            tmp += A[i] - 48;
        }
        if (m_size > i) {
            tmp += B[i] - 48;
        }
        up = tmp / 10;
        result = to_string(tmp % 10) + result;
    }
    if (up > 0) {
        result = to_string(up) + result;
    }

    cout << result << "\n";

    return 0;
}
