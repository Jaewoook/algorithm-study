#include <iostream>
#include <stack>
using namespace std;

int main() {
    bool is_vps = false;
    int T = 0, size = 0;
    string s;
    stack<int> vps;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s;
        size = s.size();

        is_vps = true;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                vps.push(s[i]);
            } else if (s[i] == ')' && !vps.empty()) {
                vps.pop();
            } else {
                is_vps = false;
                break;
            }
        }
        if (is_vps == true && vps.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        while (!vps.empty()) {
            vps.pop();
        }
    }
    return 0;
}
