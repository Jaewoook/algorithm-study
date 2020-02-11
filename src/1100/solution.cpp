#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    string board[8];

    for (int i = 0; i < 8; i++) {
        cin >> board[i];
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0) {
                if (board[i][j] == 'F' && j % 2 == 0) {
                    count++;
                }
            } else {
                if (board[i][j] == 'F' && j % 2 != 0) {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";
    return 0;
}
