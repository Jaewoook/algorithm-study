#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    string token = " ";
    int x1 = stoi(a.substr(0, a.find(token)));
    int x2 = stoi(b.substr(0, b.find(token)));
    if (x1 == x2) {
        return stoi(a.substr(a.find(token))) < stoi(b.substr(b.find(token)));
    } else {
        return x1 < x2;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0;
    string s;

    cin >> N;
    string* pos = new string[N];

    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, pos[i]);
    }
    stable_sort(pos, pos + N, compare);

    for (int i = 0; i < N; i++) {
        cout << pos[i] << "\n";
    }

    delete[] pos;
    return 0;
}
