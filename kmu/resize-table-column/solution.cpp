#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, N, count, start, end;
    vector<int> columns, resize_columns;

    cin >> T;
    while (T--) {
        cin >> N;

        columns = vector<int>(N, 0);
        resize_columns = vector<int>(N, 0);

        for (int i = 0 ; i < N; i++) {
            cin >> columns[i];
        }

        for (int i = 0; i < N; i++) {
            cin >> resize_columns[i];
        }

        count = 0;
        start = 0;
        end = N - 1;
        while (start < end) {
            if (columns[start] == resize_columns[start]) {
                start++;
                continue;
            }
            if (columns[end] == resize_columns[end]) {
                end--;
                continue;
            }

            if (columns[start] != resize_columns[start]) {
                int diff = resize_columns[start] - columns[start];
                columns[start] = resize_columns[start];
                columns[start + 1] -= diff;
                start++;
                count++;
                continue;
            }

            if (columns[end] != resize_columns[end]) {
                int diff = resize_columns[end] - columns[end];
                columns[end] = resize_columns[end];
                columns[end - 1] -= diff;
                end--;
                count++;
                continue;
            }
        }

        cout << count << "\n";
    }
    return 0;
}


// sample input
//
// 2
// 4
// 3 7 2 4
// 4 5 5 2
// 4
// 6 2 2 6
// 4 4 4 4

// sample output
//
// 3
// 2
