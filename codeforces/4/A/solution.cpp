#include <iostream>
using namespace std;

int main() {
    int kilos = 0;
    cin >> kilos;

    cout << (kilos > 2 && kilos % 2 == 0 ? "YES" : "NO") << "\n";
    return 0;
}
