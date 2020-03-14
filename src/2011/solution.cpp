#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num(char c) {
    return c - 48;
}

int main() {
    int size = 0;
    string code;

    cin >> code;

    size = code.size();
    int *dp = new int[size + 1];
    fill_n(dp, size + 1, 0);

    dp[0] = 1;
    if (size > 0) {
        dp[1] = 1;
    }

    for (int i = 1; i < size; i++) {
        dp[i + 1] = dp[i];
        if (num(code[i - 1]) * 10 + num(code[i]) <= 26) {
            dp[i + 1] = (dp[i + 1] % 1000000) + (dp[i - 1] % 1000000);
            dp[i + 1] %= 1000000;
        }
    }

    cout << dp[size] % 1000000 << "\n";

    delete[] dp;
    return 0;
}
