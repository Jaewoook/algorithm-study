#include <iostream>
#include <string>
#define L '('
#define R ')'
#define CUR stick[i]
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char prev;
    int T, count, stack, stick_size;
    string stick;
    cin >> T;
    while (T--) {
        cin >> stick;
        count = 0;
        stack = 0;
        stick_size = stick.size();
        prev = NULL;

        for (int i = 0; i < stick_size; i++) {
            if (prev == L && CUR == R) {
                --stack;
                count += stack;
            } else if (CUR == L) {
                ++stack;
            } else if (prev == R && CUR == R) {
                --stack;
                ++count;
            }
            prev = stick[i];
        }

        cout << count << "\n";
    }
    return 0;
}

// 2
// ()(((()())(())()))(())
// (()())((()))
