#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int size = 0, time = 0;

    cin >> S;
    size = S.size();

    for (int i = 0; i < size; i++) {
        int idx = S[i] - 65;
        if (idx < 3) {
            time += 2;
        } else if (idx < 6) {
            time += 3;
        } else if (idx < 9) {
            time += 4;
        } else if (idx < 12) {
            time += 5;
        } else if (idx < 15) {
            time += 6;
        } else if (idx < 19) {
            time += 7;
        } else if (idx < 22) {
            time += 8;
        } else {
            time += 9;
        }
        time += 1;
    }

    cout << time << "\n";

    return 0;
}
