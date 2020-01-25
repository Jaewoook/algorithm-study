#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned long long len[3] = { 0, };

    while (true) {
        for (int i = 0; i < 3; i++) {
            cin >> len[i];
        }

        if (len[0] == 0 && len[0] == 0 && len[0] == 0) {
            break;
        }

        sort(len, len + 3);

        cout << (len[0] * len[0] + len[1] * len[1] == len[2] * len[2] ? "right" : "wrong") << "\n";
    }

    return 0;
}
