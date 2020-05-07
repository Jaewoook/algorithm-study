#include <iostream>
using namespace std;

int main() {
    int dol = 0;
    cin >> dol;

    if (dol % 4 == 0) {
        cout << ((dol / 4) % 2 == 0 ? "CY" : "SK") << "\n";
    } else {
        cout << (dol % 2 == 0 ? "CY" : "SK") << "\n";
    }

    return 0;
}
