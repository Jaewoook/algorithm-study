#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cout.tie(0);
    ios::sync_with_stdio(0);

    long long n = 0;
    vector<int> v;

    cin >> n;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), greater<int>());

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter;
    }

    cout << "\n";

    return 0;
}
