#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    string a, b;
    int a_size = 0, b_size = 0;

    cin >> a >> b;

    a_size = a.size();
    b_size = b.size();

    int **lcs = new int*[a_size + 1];
    for (int i = 0; i <= a_size; i++) {
        lcs[i] = new int[b_size + 1];
        fill_n(lcs[i], b_size + 1, 0);
        lcs[i][0] = 0;
    }

    for (int i = 1; i <= a_size; i++) {
        for (int j = 1; j <= b_size; j++) {
            lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);

            if (a[i - 1] == b[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
        }
    }

    cout << lcs[a_size][b_size] << "\n";

    for (int i = 0; i <= a_size; i++) {
        delete[] lcs[i];
    }
    delete[] lcs;
    return 0;
}
