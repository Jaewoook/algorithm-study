#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    unordered_set<int> S, all, empty;
    for (int i = 1; i <= 20; i++) {
        all.insert(i);
    }
    int M, param;
    string cmd;
    cin >> M;
    while (M--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> param;
            S.insert(param);
        } else if (cmd == "remove") {
            cin >> param;
            S.erase(param);
        } else if (cmd == "check") {
            cin >> param;
            cout << (S.find(param) == S.end() ? 0 : 1) << "\n";
        } else if (cmd == "toggle") {
            cin >> param;
            if (S.find(param) == S.end()) {
                S.insert(param);
            } else {
                S.erase(param);
            }
        } else if (cmd == "all") {
            S = all;
        } else if (cmd == "empty") {
            S = empty;
        }
    }

    return 0;
}
