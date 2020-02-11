#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int get_max_priority(deque<int> q, int N) {
    int max_priority = 0;
    for (int i = 0; i < N; i++) {
        if (q[i] > max_priority) {
            max_priority = q[i];
        }
    }
    return max_priority;
}

int main() {
    int T = 0, N = 0, M = 0, priority = 0, printed = 0, max_priority = 0;
    deque<int> q;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        while (!q.empty()) {
            q.pop_front();
        }
        printed = 0;

        for (int i = 0; i < N; i++) {
            cin >> priority;
            q.push_back(priority);
        }

        max_priority = get_max_priority(q, N);

        while (max_priority > 0) {
            max_priority = get_max_priority(q, N);

            while (max_priority != q.front()) {
                q.push_back(q.front());
                q.pop_front();
                M = M == 0 ? q.size() - 1 : M - 1;
            }
            if (max_priority == 0 || (M == 0 && max_priority == q[M])) {
                break;
            }
            q.pop_front();
            M = M == 0 ? q.size() - 1 : M - 1;
            N--;
            printed++;
        }

        cout << printed + 1 << "\n";
    }

    return 0;
}
