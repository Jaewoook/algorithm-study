#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N = 0, num = 1, a = 0, tmp = 0, result = 0;
    cin >> N;

    num = N;
    while (num > 0) {
        num /= 10;
        a++;
    }

    num = max(N - (9 * a), 0);
    while (num <= N) {
        tmp = num;
        result = 0;
        while (tmp > 0) {
            result += tmp % 10;
            tmp /= 10;
        }
        if (num + result == N) {
            cout << num << "\n";
            return 0;
        }

        num++;
    }

    cout << "0\n";

    return 0;
}
