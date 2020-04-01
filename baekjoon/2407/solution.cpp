#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string add(string a, string b) {
    string result = "";
    int tmp = 0, up = 0, a_size = 0, b_size = 0, length = 0;
    a_size = a.size();
    b_size = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    length = max(a_size, b_size);

    for (int i = 0; i < length; i++) {
        tmp = up;
        if (a_size > i) {
            tmp += a[i] - 48;
        }
        if (b_size > i) {
            tmp += b[i] - 48;
        }
        up = tmp / 10;
        result = to_string(tmp % 10) + result;
    }
    if (up > 0) {
        result = to_string(up) + result;
    }

    return result;
}

int main() {
    int N = 0, M = 0;
    string dp[101][101];
    cin >> N >> M;

    dp[0][0] = dp[1][0] = dp[1][1] = "1";

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = "1";
            } else {
                dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[N][M] << "\n";

    return 0;
}
