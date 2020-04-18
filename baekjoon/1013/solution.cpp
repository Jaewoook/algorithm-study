#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 0, size = 0, i = 0;
    bool is_valid = false, mixed = false;
    string signal;
    cin >> T;

    while (T--) {
        cin >> signal;
        size = signal.size();
        mixed = is_valid = false;
        i = 0;

        while (i < size) {
            if (signal[i] == '0') {
                i++;
                is_valid = false;
                if (i >= size || (i < size && signal[i] != '1')) {
                    break;
                }
                is_valid = true;
                i++;
            } else {
                i++;
                is_valid = false;
                if (i >= size || (i < size && signal[i] != '0')) {
                    break;
                }
                i++;
                while (i < size && signal[i] == '0') {
                    is_valid = true;
                    i++;
                }
                if (!is_valid) {
                    break;
                }
                is_valid = false;
                while (i < size && signal[i] == '1') {
                    is_valid = true;
                    if (!mixed && i + 1 < size && signal[i + 1] == '1') {
                        mixed = true;
                    }
                    i++;
                }
                if (!is_valid) {
                    break;
                }
                if (mixed) {
                    if (i + 1 < size && signal[i + 1] == '0') {
                        i -= 1;
                    }
                }
                mixed = false;
            }
        }

        cout << (is_valid ? "YES" : "NO") << "\n";
    }

    return 0;
}
