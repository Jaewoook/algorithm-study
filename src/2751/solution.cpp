#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T = 0;
    cin >> T;
    int* num = new int[T];

    for (int i = 0; i < T; i++) {
        cin >> num[i];
    }

    sort(num, num + T);

    for (int i = 0; i < T; i++) {
        cout << num[i] << "\n";
    }
    return 0;
}
