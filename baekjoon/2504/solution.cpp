#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_left(char c) {
    return c == '(' || c == '[';
}

int get_value(char c) {
    if (c == '(' || c == ')') {
        return 2;
    }
    if (c == '[' || c == ']') {
        return 3;
    }
    return 0;
}

int compute(string parentheses, int &position, int size, int depth) {
    stack<char> s;
    int sum = 0;
    char parenthesis, prev_parenthesis;
    while (position < size) {
        parenthesis = parentheses[position];

        if (is_left(parenthesis)) {
            if (s.empty()) {
                s.push(parenthesis);
                position++;
                sum += get_value(parenthesis);
            } else if (is_left(s.top())) {
                sum -= get_value(s.top());
                int nested_value = compute(parentheses, position, size, depth + 1);
                if (nested_value == 0) {
                    sum = 0;
                    break;
                }
                sum += get_value(s.top()) * nested_value;
            } else {
                s.push(parenthesis);
                position++;
                sum += get_value(parenthesis);
            }
        } else {
            if (s.empty() && depth == 0) {
                sum = 0;
                break;
            } else if (s.empty()) {
                break;
            } else if ((s.top() == '(' && parenthesis == ')') || (s.top() == '[' && parenthesis == ']')) {
                s.pop();
                position++;
            } else {
                sum = 0;
                break;
            }
        }
    }

    if (!s.empty()) {
        sum = 0;
    }

    return sum;
}

int main() {
    string parentheses;

    cin >> parentheses;
    const int size = parentheses.size();
    int position = 0;
    cout << compute(parentheses, position, size, 0) << "\n";

    return 0;
}
