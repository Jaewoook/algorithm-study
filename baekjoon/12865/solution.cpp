//  TODO
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N = 0, K = 0, W = 0, V = 0;
    vector<pair<int, int> > o;

    cin >> N >> K;
    // pair<int, int> *dp = new pair<int, int>[N];
    pair<int, int> *arr = new pair<int, int>[N];
    int *dp = new int[K + 1];
    fill_n(dp, K + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> W >> V;

        arr[i] = make_pair(W, V);
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < N; j++) {
            arr[j].first
        }
    }

    cout << max_value << "\n";

    delete[] dp;
    delete[] arr;
    return 0;
}
