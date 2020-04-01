//  TODO
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, tmp = 0, min = 0, max = 0, sum = 0, count = 0, max_count = 1, frequent = 0;
    vector<int> v;
    vector<int> max_v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }
    //  push big meaningless value for correct calculation

    sort(v.begin(), v.end());
    v.push_back(10000);
    max = v[N - 1];
    min = v[0];

    //  set value as out of input bound
    tmp = -10000;
    for (int i = 0; i <= N; i++) {
        if (tmp == v[i]) {
            count++;
        } else {
            if (max_count < count) {
                max_count = count;
                max_v.clear();
                max_v.push_back(tmp);
            } else if (max_count == count) {
                max_v.push_back(tmp);
            }
            count = 1;
            tmp = v[i];
        }
    }

    if (max_v.size() > 1) {
        frequent = max_v[1];
    } else {
        frequent = max_v[0];
    }

    //  remove meaningless value
    v.pop_back();

    cout << (int) round((float) sum / N) << "\n";
    cout << v[N / 2] << "\n";
    cout << frequent << "\n";
    cout << max - min << "\n";

    return 0;
}
