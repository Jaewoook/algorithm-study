#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int> &C) {
    cout << "\nDisplay cost\n";
    for (auto i = C.begin(); i != C.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";
}

pair<int, int> find_pair(vector<int> &C, int P) {
    int first = 0;
    int second = C.size() - 1;
    while (C[first] + C[second] != P) {
        if (C[first] + C[second] < P) {
            second--;
        } else if (C[first] +C[second] > P) {
            first++;
        }
    }

    pair<int, int> result = make_pair(C[first], C[second]);
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, P;
    vector<int> C;

    cin >> T;
    while (T--) {
        cin >> N >> P;
        C = vector<int>(N);
        while (N--) {
            cin >> C[N];
        }
        sort(C.begin(), C.end(), greater());
        // display(C);
        pair<int, int> r = find_pair(C, P);
        cout << r.second << " " << r.first << "\n";
    }

    return 0;
}

// 2
// 3 7
// 2 4 5
// 6 10
// 5 2 3 7 1 5
