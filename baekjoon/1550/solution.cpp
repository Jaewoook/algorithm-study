#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int result = 0, size = 0;
    string s;
    cin >> s;

    size = s.size();
    for (int i = 0; i < size; i++) {
        result += pow(16, i) * (s[size - i - 1] < 60 ? s[size - i - 1] - 48 : 10 + s[size - i - 1] - 65);
    }
    cout << result << "\n";
    return 0;
}
