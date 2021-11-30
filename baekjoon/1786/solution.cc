#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string T, P;
    vector<int> pos, p;

    getline(cin, T);
    getline(cin, P);

    p = vector<int>(P.size(), 0);
    //  build fail array
    if (P.size() > 1) {
        for (int index = 1, current = 0; index < P.size(); index++) {
            while (current > 0 && P[index] != P[current]) {
                current = p[current - 1];
            }

            if (P[index] == P[current]) {
                p[index] = ++current;
            }
        }
    }

    for (int index = 0, current = 0; index < T.size(); index++) {
        while (current > 0 && T[index] != P[current]) {
            current = p[current - 1];
        }

        if (T[index] == P[current]) {
            if (current == P.size() - 1) {
                pos.push_back(index - current);
                current = p[current];
                continue;
            }
            current++;
        }
    }

    cout << pos.size() << "\n";
    for (auto i = pos.begin(); i != pos.end(); i++) {
        cout << (*i) + 1 << " ";
    }
    cout << "\n";

    return 0;
}
