#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int *num = new int[N + 1];

    num[0] = 1;
    num[1] = 1;

    for (int i = 2; i <= N; i++) {
        num[i] = (num[i - 2] + num[i - 1]) % 10007;
    }

    cout << num[N] << "\n";

    delete[] num;

    return 0;
}
