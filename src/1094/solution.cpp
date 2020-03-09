#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    vector<int>::iterator iter;
    v.push_back(64);
    int X = 0, sum = 0;

    cin >> X;

    while (true) {
        sum = 0;
        for (iter = v.begin(); iter != v.end(); iter++) {
            sum += *iter;
        }

        if (sum == X) {
            break;
        } else if (sum > X) {
            int half = v.back() / 2;
            v.pop_back();
            if (sum - half >= X) {
                v.push_back(half);
            } else {
                v.push_back(half);
                v.push_back(half);
            }
        }
    }

    cout << v.size() << "\n";

    return 0;
}
