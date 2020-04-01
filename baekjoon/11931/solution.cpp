#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int num[N];

    for (int i = 0; i < N; i++) {
       cin >> num[i];
    }

    sort(num, num + N, greater<int>());

    for (int i = 0; i < N; i++) {
        cout << num[i] << "\n";
    }

    return 0;
}
