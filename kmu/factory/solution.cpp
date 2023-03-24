#include <iostream>
#include <string>
#include <queue>

#define ORDER "ORDER"
#define DONE "DONE"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, count, rest_a, rest_b;
    string type, target;
    queue<int> f_a, f_b;
    cin >> T;
    while (T--) {
        f_a = queue<int>();
        f_b = queue<int>();
        rest_a = rest_b = 0;
        cin >> N;
        cin.ignore();

        while (N--) {
            cin >> type;

            if (type == ORDER) {
                cin >> count >> target;
                if (target == "A") {
                    f_a.push(count);
                    rest_a += count;
                } else if (target == "B") {
                    f_b.push(count);
                    rest_b += count;
                } else {
                    if (rest_b < rest_a) {
                        rest_b += count;
                        f_b.push(count);
                    } else {
                        rest_a += count;
                        f_a.push(count);
                    }
                }
            } else if (type == DONE) {
                cin >> target;

                if (target == "A") {
                    rest_a -= f_a.front();
                    f_a.pop();
                } else {
                    rest_b -= f_b.front();
                    f_b.pop();
                }
            }
        }
        cout << rest_a << " " << rest_b << "\n";
    }

    return 0;
}

// 2
// 5
// ORDER 5 C
// ORDER 3 B
// ORDER 1 B
// ORDER 2 C
// DONE B
// 8
// ORDER 2 C
// ORDER 15 C
// DONE B
// ORDER 7 C
// ORDER 4 C
// DONE A
// ORDER 8 B
// DONE B
