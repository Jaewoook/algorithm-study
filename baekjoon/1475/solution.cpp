#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n[10] = {};
    string num;
    int size;
    cin >> num;
    size = num.size();

    for (int i = 0; i < size; i++) {
        n[num.at(i) - '0']++;
    }
    n[6] += n[9];
    n[6] = ceil(n[6] / (float) 2);
    size = 0;
    for (int i = 0; i < 9; i++) {
        if (n[i] > size) {
            size = n[i];
        }
    }

    cout << size << "\n";

    return 0;
}
