#include <iostream>

using namespace std;

int main() {
    int N = 0, a = -1, n = 0, result = 0, count = 0;
    cin >> N;

    a = N;

    do {
        n = a % 10;
        result = (a / 10 + n) % 10;
        count++;
        a = n * 10 + result;
    } while (N != a);

    cout << count << "\n";

    return 0;
}
