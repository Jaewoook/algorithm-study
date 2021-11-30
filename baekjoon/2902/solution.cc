#include <iostream>
#include <string.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    char name[101];
    int len;

    cin >> name;
    len = strlen(name);
    for (int i = 0; i < len; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            cout << name[i];
        }
    }
    cout << "\n";

    return 0;
}
