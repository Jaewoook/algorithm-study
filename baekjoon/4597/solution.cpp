#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int count = 0;
    bool odd = false;
    while (1) {
        cin >> s;
        if (s == "#") break;
        count = 0;
        odd = s.at(s.size() - 1) == 'o';
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') count++;
        }
        s.erase(s.size() - 1);
        if (count & 1) {
            s += odd ? '0' : '1';
        } else {
            s += odd ? '1' : '0';
        }
        cout << s << "\n";
    }
    return 0;
}
