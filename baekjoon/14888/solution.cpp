#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000000
#define MIN -1000000000

void dfs(int *num, int operators[], const int &N, int value, int depth, int &max_val, int &min_val) {
    if (depth == N) {
        max_val = max(max_val, value);
        min_val = min(min_val, value);
        return;
    }

    int next_value = value;
    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            --operators[i];
            switch (i) {
            case 0:
                next_value = value + num[depth];
                break;
            case 1:
                next_value = value - num[depth];
                break;
            case 2:
                next_value = value * num[depth];
                break;
            case 3:
                next_value = value / num[depth];
                break;
            }
            dfs(num, operators, N, next_value, depth + 1, max_val, min_val);
            ++operators[i];
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, max_val = MIN, min_val = MAX, operators[4] = {};
    cin >> N;
    int *num = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    dfs(num, operators, N, num[0], 1, max_val, min_val);
    cout << max_val << "\n" << min_val << "\n";

    delete[] num;
    return 0;
}
