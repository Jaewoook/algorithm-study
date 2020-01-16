#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    while (!cin.eof()) {
        getline(cin, S);
        cout << S << "\n";
    }
    return 0;
}
