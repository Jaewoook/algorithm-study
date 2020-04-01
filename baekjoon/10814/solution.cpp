#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string name1, string name2) {
    int age1 = stoi(name1.substr(0, name1.find(" ")));
    int age2 = stoi(name2.substr(0, name2.find(" ")));

    if (age1 == age2) {
        return false;
    } else {
        return age1 < age2;
    }
}

int main() {
    int T = 0;
    cin >> T;
    cin.ignore();
    string* rows = new string[T];

    for (int i = 0; i < T; i++) {
        getline(cin, rows[i]);
    }

    stable_sort(rows, rows + T, compare);

    for (int i = 0; i < T; i++) {
        cout << rows[i] << "\n";
    }

    delete[] rows;
    return 0;
}
