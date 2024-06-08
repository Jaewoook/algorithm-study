#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
#define ll long long int
#define pq priority_queue
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
    FASTIO;

    int N;
    cin >> N;

    vector<int> cost(N), happiness(N);
    vector<vector<int>> dp(N + 1, vector<int>(101, 0));

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> happiness[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int hp = 1; hp <= 100; hp++) {
            dp[i][hp] = dp[i - 1][hp];

            if (hp - cost[i - 1] <= 0) {
                continue;
            }

            dp[i][hp] = max(dp[i][hp], dp[i - 1][hp - cost[i - 1]] + happiness[i - 1]);
        }
    }

    cout << dp[N][100] << "\n";

    return 0;
}
