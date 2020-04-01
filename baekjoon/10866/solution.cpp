#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, n = 0;
    string s;
    deque<int> d;

    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        getline(cin, s);

        if (s.find("push") != string::npos) {
            n = stoi(s.substr(s.find(" ")));
            if (s.find("front") != string::npos) {
                d.push_front(n);
            } else {
                d.push_back(n);
            }
        } else if (s.find("pop") != string::npos) {
            if (d.size() == 0) {
                cout << "-1\n";
            } else if (s.find("front") != string::npos) {
                cout << d.front() << "\n";
                d.pop_front();
            } else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        } else if (s.find("size") != string::npos) {
            cout << d.size() << "\n";
        } else if (s.find("empty") != string::npos) {
            cout << (d.empty() ? 1 : 0) << "\n";
        } else if (s.find("front") != string::npos) {
            cout << (d.size() > 0 ? d.front() : -1) << "\n";
        } else if (s.find("back") != string::npos) {
            cout << (d.size() > 0 ? d.back() : -1) << "\n";
        }
    }
    return 0;
}
