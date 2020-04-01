#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    for (char c = 97; c <= 122; c++) {
        int pos = S.find(c);
        cout << (pos == string::npos ? -1 : pos) << " ";
    }

    return 0;
}
