#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, push = 0, pop = 0, size = 0, empty = 0, front = 0, back = 0;
    string s;
    queue<int> q;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        getline(cin, s);

        push = s.find("push ");
        pop = s.find("pop");
        size = s.find("size");
        empty = s.find("empty");
        front = s.find("front");
        back = s.find("back");

        if (push != string::npos) {
            q.push(stoi(s.substr(s.find(" "))));
        }
        if (pop != string::npos) {
            if (q.size() > 0) {
                cout << q.front() << "\n";
                q.pop();
            } else {
                cout << "-1\n";
            }
        }
        if (size != string::npos) {
            cout << q.size() << "\n";
        }
        if (empty != string::npos) {
            cout << (q.empty() ? 1 : 0) << "\n";
        }
        if (front != string::npos) {
            cout << (q.size() > 0 ? q.front() : -1) << "\n";
        }
        if (back != string::npos) {
            cout << (q.size() > 0 ? q.back() : -1) << "\n";
        }
    }
    return 0;
}
