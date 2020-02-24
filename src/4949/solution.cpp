#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

void clear_stack(stack<char> &s) {
    stack<char> empty;
    swap(s, empty);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s = "";
    stack<char> stack;
    int size = 0;
    bool is_pair = false;
    while (true) {
        getline(cin, s);
        if (s.size() == 1 && s[0] == '.') {
            break;
        }
        size = s.size();
        clear_stack(stack);
        is_pair = true;

        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[') {
                stack.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']') {
                if (stack.size() == 0) {
                    is_pair = false;
                    break;
                } else if (stack.top() == '(' && s[i] == ')') {
                    stack.pop();
                } else if (stack.top() == '[' && s[i] == ']') {
                    stack.pop();
                } else {
                    is_pair = false;
                    break;
                }
            }
        }
        if (!is_pair || stack.size() > 0) {
            cout << "no" << "\n";
        } else {
            cout << "yes" << "\n";
        }
    }

    return 0;
}
