#include <iostream>
using namespace std;

int main() {
    int n = 0, sum = 0;

    for (int i = 0; i < 5; i++) {
        cin >> n;
        sum += n * n;
    }
    cout << sum % 10 << "\n";
    return 0;
}
