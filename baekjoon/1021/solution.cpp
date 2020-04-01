#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, x = 0, tmp = 0, front = 0, size = 0, count = 0;
    deque<int> d;
    queue<int> q;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        d.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        cin >> x;
        q.push(x);
    }

    while (!q.empty()) {
        front = q.front();
        size = d.size();


        for (deque<int>::iterator iter = d.begin(); iter != d.end(); iter++) {
            if (*iter == front) {
                x = iter - d.begin();
                q.pop();
                break;
            }
        }

        if (x < size - x) {
            while (d.front() != front) {
                tmp = d.front();
                d.pop_front();
                d.push_back(tmp);
            }
        } else {
            while (d.front() != front) {
                tmp = d.back();
                d.pop_back();
                d.push_front(tmp);
            }
        }
        d.pop_front();
        count += min(x, size - x);
    }

    cout << count << "\n";

    return 0;
}
