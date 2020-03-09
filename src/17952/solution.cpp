#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, A = 0, T = 0, score = 0;
    bool homework = false;
    stack<pair<int, int> > s;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> homework;

        if (homework) {
            cin >> A >> T;
            s.push(make_pair(A, T));
        }

        if (!s.empty()) {
            pair<int, int> hw = s.top();
            s.pop();
            hw.second--;
            if (hw.second > 0) {
                s.push(hw);
            } else {
                score += hw.first;
            }
        }
    }

    cout << score << "\n";

    return 0;
}
