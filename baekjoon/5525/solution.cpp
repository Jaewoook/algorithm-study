#include <iostream>
#include <string>
using namespace std;
#define I 'I'
#define O 'O'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0, count = 0;
    string s;
    bool is_ioi = false;
    cin >> N >> M >> s;

    for (int i = 0; i < M; i++) {
        if (i + 2 < M) {
            if (s[i] == I && s[i + 1] == O && s[i + 2] == I) {
                int o_count = 0;
                while (s[i] == I && s[i + 1] == O) {
                    o_count++;
                    i += 2;
                    if (s[i] == I && o_count == N) {
                        count++;
                        o_count--;
                    }
                }
            }
        }
    }

    cout << count << "\n";

    return 0;
}
