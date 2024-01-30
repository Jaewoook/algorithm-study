#include <iostream>
#include <vector>
using namespace std;

int min(int a1, int a2) {
    return a1 < a2 ? a1 : a2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int charge, tmp;
    cin >> charge;
    vector<int> DP(6, 0);

   DP[2] = 1;
   DP[4] = 2;
   DP[5] = 1;

   for (int i = 6; i <= charge; i++) {
    tmp = 0;

    if (i % 5 == 0) {
        tmp = i / 5;
    } else if (i % 2 == 0) {
        tmp = i / 2;
    }

    if (DP[i - 2] != 0) {
        tmp = tmp == 0 ? DP[i - 2] + 1 : min(DP[i - 2] + 1, tmp);
    }
    if (DP[i - 5] != 0) {
        tmp = tmp == 0 ? DP[i - 5] + 1 : min(DP[i - 5] + 1, tmp);
    }

    DP.push_back(tmp);
   }

    cout << (DP[charge] != 0 ? DP[charge] : -1) << "\n";
    return 0;
}
