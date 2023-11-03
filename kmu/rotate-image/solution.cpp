#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_image(vector<vector<int>> &image) {
    for (auto i = image.begin(); i != image.end(); i++) {
        for (auto j = (*i).begin(); j != (*i).end(); j++) {
            cout << *j;
        }
        cout << "\n";
    }
}

void rotate(vector<vector<int>> *image, int N) {
    vector<vector<int>> rotated_image(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated_image[j][N - 1 - i] = (*image)[i][j];
        }
    }

    *image = rotated_image;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, A;
    vector<vector<int>> image;
    string line;
    cin >> T;
    while (T--) {
        cin >> N >> A;

        image = vector<vector<int>>(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            cin >> line;

            for (int j = 0; j < N; j++) {
                image[i][j] = line[j] - '0';
            }
        }

        if (A < 0) {
            A = 360 + A;
        }
        int count = A / 90;
        for (int i = 0; i < count; i++) {
            rotate(&image, N);
        }
        print_image(image);
    }

    return 0;
}


// sample input
//
// 2
// 5 90
// 01876
// 16521
// 46125
// 41628
// 52438
// 5 -90
// 01876
// 16521
// 46125
// 41628
// 52438

// sample output
//
// 54410
// 21661
// 46158
// 32227
// 88516
// 61588
// 72223
// 85164
// 16612
// 01445
