#include <iostream>
#include <queue>
using namespace std;

int main() {
    int X = 0, count = -1;
    queue<long long> q;
    cin >> X;

    if (X < 10) {
        cout << X << "\n";
    } else if (X > 1022) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < 10; i++) {
            q.push(i);
            count++;
        }

        while (true) {
            if (q.front() < 10) {
                for (int i = 0; i < q.front(); i++) {
                    if (count == X) {
                        break;
                    }
                    q.push(q.front() * 10 + i);
                    count++;
                }
                q.pop();
            } else {
                int len = q.front() % 10;
                for (int i = 0; i < len; i++) {
                    if (count == X) {
                        break;
                    }
                    q.push(q.front() * 10 + i);
                    count++;
                }
                q.pop();
            }

            if (count == X) {
                break;
            }
        }

        cout << q.back() << "\n";
    }
    return 0;
}
