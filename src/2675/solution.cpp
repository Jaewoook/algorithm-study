#include <iostream>
#include <string>

using namespace std;

int main() {
    int T = 0, R = 0;
    string S;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> R >> S;
        for (int j = 0; j < R * S.size(); j++) {
            cout << S.at(j / R);
        }
        cout << "\n";
    }

    return 0;
}
