#include <iostream>
using namespace std;

int main() {

    int N, a, b;
    cin >> N;
    pair<int, int> *info = new pair<int, int>[N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        info[i] = make_pair(a, b);
    }

    for (int i = 0; i < N; i++) {
        int order = 1;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (info[i].first < info[j].first && info[i].second < info[j].second) {
                order++;
            }
        }
        cout << order << " ";
    }
    cout << "\n";

    delete[] info;
    return 0;
}
