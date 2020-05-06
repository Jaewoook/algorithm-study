#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, top = 0;
    stack<pair<int, int> > tower;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> top;
        while (!tower.empty()) {
            if (tower.top().first > top) {
                cout << tower.top().second << " ";
                break;
            }
            tower.pop();
        }

        if (tower.empty()) {
            cout << "0 ";
        }
        tower.push(make_pair(top, i));
    }

    return 0;
}
