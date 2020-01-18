#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    string N;
    int size = 0;
    cin >> N;

    size = N.size();
    switch (size % 3) {
        case 1:
            N = "00" + N;
            break;
        case 2:
            N = "0" + N;
            break;
    }
    size = N.size();
    for (int i = 0; i < size; i += 3) {
        cout << (N[i] - 48) * 4 + (N[i + 1] - 48) * 2 + (N[i + 2] - 48);
    }

    cout << "\n";

    return 0;
}
