#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int E = 0, i = 2, count = 0;
    cin >> E;

    while (E > 1) {
        if (E % i == 0) {
            count++;
            E /= i;
        } else if (E % i != 0) {
            i++;
        } else if (E < i) {
            break;
        }
    }

    cout << ceil(log2(count)) << "\n";
    return 0;
}
