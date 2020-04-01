//  참고: https://www.opentutorials.org/module/1544/9532
#include <iostream>
using namespace std;
#define MOD 1234567891

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int L = 0;
    unsigned long long hash = 0, R = 1;
    cin >> L;
    char *str = new char[L];
    cin >> str;

    for (int i = 0; i < L; i++) {
        hash +=  (str[i] - 'a' + 1) * R;
        R *= 31;
        hash %= MOD;
        R %= MOD;
    }

    cout << hash << "\n";

    delete[] str;
    return 0;
}
