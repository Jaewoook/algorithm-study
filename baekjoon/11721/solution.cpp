#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    int size = 0;
    cin >> S;
    size = S.size();
    size = size / 10 + 1;
    for (int i = 0; i < size; i++) {
        cout << S.substr(i * 10, 10) << "\n";
    }

    return 0;
}
