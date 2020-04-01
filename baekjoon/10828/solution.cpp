#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, push = 0, pop = 0, size = 0, empty = 0, top = 0;
    string s;
    stack<int> stack;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        getline(cin, s);
        push = s.find("push ");
        pop = s.find("pop");
        size = s.find("size");
        empty = s.find("empty");
        top = s.find("top");

        if (push != string::npos) {
            stack.push(stoi(s.substr(s.find(" "))));
        }
        if (pop != string::npos) {
            if (stack.empty()) {
                cout << "-1\n";
            } else {
                cout << stack.top() << "\n";
                stack.pop();
            }
        }
        if (size != string::npos) {
            cout << stack.size() << "\n";
        }
        if (empty != string::npos) {
            cout << (stack.empty() ? 1 : 0) << "\n";
        }
        if (top != string::npos) {
            cout << (stack.size() > 0 ? stack.top() : -1) << "\n";
        }
    }

    return 0;
}
