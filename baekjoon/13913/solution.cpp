#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void print(int *map, int K) {
    if (map[K] != K) {
        print(map, map[K]);
    }
    cout << K << " ";
}

void clear_queue(queue<int> &q) {
    queue<int> empty;
    swap(q, empty);
}

int main() {
    int N = 0, K = 0, count = 0;
    queue<int> q, tmp;
    int *map = new int[100001];
    fill_n(map, 100001, -1);
    bool *v = new bool[100001];
    fill_n(v, 100001, false);
    int next_i = 0, top = 0;
    bool finished = false;

    cin >> N >> K;
    if (N == K) {
        cout << "0\n" << N;
    } else {
        q.push(N);
        map[N] = N;
        v[N] = true;
        while (!q.empty()) {
            tmp = q;
            clear_queue(q);

            while (!tmp.empty()) {
                top = tmp.front();
                tmp.pop();

                for (int i = 0; i < 3; i++) {
                    switch (i) {
                        case 0:
                            next_i = top - 1;
                            break;
                        case 1:
                            next_i = top + 1;
                            break;
                        case 2:
                            next_i = top * 2;
                            break;
                    }
                    if (next_i < 0 || next_i > 100000 || v[next_i]) {
                        continue;
                    }
                    v[next_i] = true;
                    map[next_i] = top;
                    q.push(next_i);
                    if (next_i == K) {
                        finished = true;
                        break;
                    }
                }
            }

            count++;
            if (finished) {
                break;
            }
        }

        cout << count << "\n";
        print(map, K);
    }

    delete[] v;
    return 0;
}
