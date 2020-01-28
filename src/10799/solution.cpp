#include <iostream>
#include <string>
using namespace std;

int main() {
    int size = 0, sticks = 0, pieces = 0;
    char prev = 0;
    string s;

    cin >> s;
    size = s.size();
    for (int i = 0; i < size; i++) {
        if (prev == '(' && s[i] == ')') {
            sticks--;
            pieces--;
            pieces += sticks;
        }
        if (s[i] == '(') {
            sticks++;
            pieces++;
        } else if (prev == ')' && s[i] == ')') {
            sticks--;
        }
        prev = s[i];
    }

    cout << pieces << "\n";
    return 0;
}
