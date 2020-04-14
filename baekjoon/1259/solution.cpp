#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s1, s2;
    int size = 0;

    while (true) {
        cin >> s1;
        s2 = "";
        if (s1 == "0") {
            break;
        }

        size = s1.size();
        for (int i = size - 1; i >= 0; i--) {
            s2 += s1[i];
        }
        cout << (s1 == s2 ? "yes" : "no") << "\n";
    }
    return 0;
}
