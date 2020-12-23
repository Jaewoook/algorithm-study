#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, s_size;
    list<char> l;
    list<char>::iterator cursor;
    string s;

    cin >> T;
    while (T--) {
        cin >> s;

        l.clear();
        cursor = l.begin();
        s_size = s.size();

        for (int i = 0; i < s_size; i++) {
            switch (s[i]) {
                case '<':
                    if (cursor != l.begin()) {
                        cursor--;
                    }
                    break;
                case '>':
                    if (cursor != l.end()) {
                        cursor++;
                    }
                    break;
                case '-':
                    if (!l.empty() && cursor != l.begin()) {
                        cursor--;
                        cursor = l.erase(cursor);
                    }
                    break;
                default:
                    cursor = l.insert(cursor, s[i]);
                    cursor++;
                    break;
            }
        }
        for (cursor = l.begin(); cursor != l.end(); cursor++) {
            cout << *cursor;
        }
        cout << "\n";
    }

    return 0;
}
