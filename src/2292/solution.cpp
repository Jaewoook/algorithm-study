#include <iostream>
using namespace std;

int getSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n--;
    }
    return sum;
}

int main() {
    int N = 0, num = 0, mul = 0;
    cin >> N;

    while (num < N) {
        num = getSum(mul) * 6 + 1;
        mul++;
    }

    cout << mul << "\n";

    return 0;
}
