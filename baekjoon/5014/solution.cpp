#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void bfs(int S, int G, int U, int D, int F, int *v) {
    queue<int> q;
    int cur = S;

    q.push(S);
    v[cur] = 0;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur + U <= F && v[cur + U] < 0) {
            v[cur + U] = v[cur] + 1;
            q.push(cur + U);
            if (cur + U == G) {
                break;
            }
        }
        if (cur - D > 0 && v[cur - D] < 0) {
            v[cur - D] = v[cur] + 1;
            q.push(cur - D);
            if (cur - D == G) {
                break;
            }
        }
    }
}

int main() {
    int F = 0, S = 0, G = 0, U = 0, D = 0;
    cin >> F >> S >> G >> U >> D;

    int *v = new int[F + 1];
    fill_n(v, F + 1, -1);

    if (S == G) {
        cout << "0\n";
    } else {
        bfs(S, G, U, D, F, v);
        if (v[G] > -1) {
            cout << v[G] << "\n";
        } else {
            cout << "use the stairs\n";
        }
    }

    delete[] v;
    return 0;
}
