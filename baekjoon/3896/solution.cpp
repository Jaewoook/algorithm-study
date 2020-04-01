#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_SIZE 1299710

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    bool arr[MAX_SIZE] = { false, };
    int T = 0, num = 0, prev = 1;
    vector<int> prime;
    vector<int>::iterator iter;

    fill_n(arr, MAX_SIZE, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i * i <= MAX_SIZE - 1; i++) {
        if (arr[i] == true) {
            for (int j = i * i; j <= MAX_SIZE - 1; j += i) {
                arr[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAX_SIZE - 1; i++) {
        if (arr[i]) {
            prime.push_back(i);
        }
    }

    cin >> T;

    for (int n = 0; n < T; n++) {
        cin >> num;
        if (arr[num]) {
            cout << "0\n";
            continue;
        }

        for (iter = prime.begin(); iter != prime.end(); iter++) {
            if (num > prev && num < *iter) {
                cout << *iter - prev << "\n";
                break;
            }
            prev = *iter;
        }
    }

    return 0;
}
