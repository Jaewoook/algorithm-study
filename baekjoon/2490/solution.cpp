#include <iostream>
using namespace std;

int main() {
    cin.tie(0);

    int N = 3, count = 0, t;
    char result;

    while (N--) {
        count = 0;
        for (int i = 0; i < 4; i++) {
            cin >> t;
            if (t == 0) {
                count++;
            }
        }
        switch (count) {
        case 0:
            result = 'E';
            break;
        case 1:
            result = 'A';
            break;
        case 2:
            result = 'B';
            break;
        case 3:
            result = 'C';
            break;
        case 4:
            result = 'D';
            break;
        }
        cout << result << "\n";
    }

    return 0;
}
