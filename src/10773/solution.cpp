#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, a = 0;
    stack<int> s;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a != 0) {
            s.push(a);
        } else {
            s.pop();
        }
    }

    a = 0;
    while(!s.empty()) {
        a += s.top();
        s.pop();
    }

    cout << a << "\n";

    return 0;
}
