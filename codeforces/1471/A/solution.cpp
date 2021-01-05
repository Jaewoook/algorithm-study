#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T, N, X, min_val, max_val;
    long long sum;
    int *arr;
    cin >> T;
    while (T--) {
        cin >> N >> X;
        arr = new int[N];
        min_val = max_val = sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            max_val += ceil(arr[i] / (double) X);
            sum += arr[i];
        }
        min_val = ceil(sum / (double) X);

        cout << min_val << " " << max_val << "\n";
        delete[] arr;
    }


    return 0;
}
