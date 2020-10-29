#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int N = 0, a = 0;
    bool possible = true;
    stack<int> s;
    queue<int> q, result;

    cin >> N;
    int *seq = new int[N + 1];
    fill_n(seq, N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> a;
        q.push(a);
        seq[a]++;
        if (seq[a] > 1) {
            possible = false;
        }
    }

    if (possible) {
        s.push(0);
        int i = 0;
        while (!q.empty() && i <= N) {
            if (s.top() < q.front()) {
                s.push(++i);
                result.push(1);
            } else if (s.top() == q.front()) {
                s.pop();
                q.pop();
                result.push(0);
            } else {
                possible = false;
                break;
            }
        }
        if (!q.empty() || i > N) {
            possible = false;
        }
    }

    if (possible) {
        while (!result.empty()) {
            cout << (result.front() == 1 ? "+" : "-") << "\n";
            result.pop();
        }
    } else {
        cout << "NO\n";
    }

    delete[] seq;
    return 0;
}
