#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, size = 0;
    cin >> N;
    string *results = new string[N];

    for (int i = 0; i < N; i++) {
        cin >> results[i];
    }

    size = results[0].size();
    for (int i = 0; i < size; i++) {
        bool is_same = true;
        char c = results[0][i];
        for (int j = 1; j < N; j++) {
            if (c != results[j][i]) {
                is_same = false;
            }
        }
        c = is_same ? c : '?';
        cout << c;
    }
    cout << "\n";

    return 0;
}
