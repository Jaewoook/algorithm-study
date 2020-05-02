#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void clear_queue(queue<int> &q) {
    queue<int> empty;
    swap(q, empty);
}

int main() {
    int N = 0, K = 0;
    bool *v = new bool[100001];
    fill_n(v, 100001, false);
    int count = 0, time = 0;
    queue<int> q, tmp;
    int top = 0, next_i = 0;
    bool finished = false;

    cin >> N >> K;

    if (N != K) {
        q.push(N);

        while (!q.empty()) {
            tmp = q;
            clear_queue(q);

            while (!tmp.empty()) {
                top = tmp.front();
                v[top] = true;
                tmp.pop();

                for (int i = 0; i < 3; i++) {
                    switch (i) {
                        case 0:
                            next_i = top + 1;
                            break;
                        case 1:
                            next_i = top - 1;
                            break;
                        case 2:
                            next_i = top * 2;
                            break;
                    }
                    if (next_i < 0 || next_i > 100000 || v[next_i]) {
                        continue;
                    }

                    if (next_i != K) {
                        q.push(next_i);
                    } else {
                        count++;
                        finished = true;
                    }
                }
            }

            time++;
            if (finished) {
                break;
            }
        }
    }

    cout << time << "\n" << (N == K ? 1 : count) << "\n";

    delete[] v;
    return 0;
}
