#include <iostream>

using namespace std;

int main() {
    int n[5] = {0, }, tmp = 0;

    for (int i = 0; i < 5; i++) {
        cin >> n[i];
    }

    while (!(n[0] == 1 && n[1] == 2 && n[2] == 3 && n[3] == 4 && n[4] == 5)) {
        for (int i = 0; i < 4; i++) {
            if (n[i] > n[i + 1]) {
                tmp = n[i];
                n[i] = n[i + 1];
                n[i + 1] = tmp;
                for (int j = 0; j < 5; j++) {
                    cout << n[j] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
