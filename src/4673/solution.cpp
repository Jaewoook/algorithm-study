#include <iostream>

using namespace std;

int main() {
    bool arr[10001] = {false, };
    int N = 0, sum = 0;

    for (int i = 1; i <= 10000; i++) {
        N = i;
        sum += N;
        while (N > 0) {
            sum += N % 10;
            N /= 10;
        }
        if (sum <= 10000) {
            arr[sum] = true;
        }
        sum = 0;
    }

    for (int i = 1; i <= 10000; i++) {
        if (arr[i] == 0) {
            cout << i << "\n";
        }
    }

    return 0;
}
