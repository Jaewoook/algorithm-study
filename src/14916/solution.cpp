#include <iostream>
using namespace std;

int main() {
    int coin = 0, tmp = 0, count = 0;
    cin >> coin;

    tmp = coin;
    if (coin > 4) {
        count = coin / 5;
        coin %= 5;
    }

    if (coin != 0) {
        if (coin % 2 == 0) {
            count += coin / 2;
        } else {
            while (true) {
                coin += 5;
                count--;
                if (coin >= tmp) {
                    count = -1;
                    break;
                } else if (coin % 2 == 0) {
                    count += coin / 2;
                    break;
                }
            }
        }
    }

    cout << count << "\n";
    return 0;
}
