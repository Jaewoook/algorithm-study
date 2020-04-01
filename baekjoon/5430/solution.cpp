#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, N = 0, input_size = 0, p_size = 0, d_count = 0, d_size = 0, num = 0;
    bool front = true, is_error = false;
    string p, arr_input;
    deque<int> d;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> p >> N >> arr_input;
        front = true;
        is_error = false;
        d_count = 0;
        num = 0;
        d.clear();
        input_size = arr_input.size();
        p_size = p.size();

        if (N > 0) {
            for (int j = 1; j < input_size; j++) {
                if (arr_input[j] >= '0' && arr_input[j] <= '9') {
                    num *= 10;
                    num += arr_input[j] - 48;
                } else {
                    d.push_back(num);
                    num = 0;
                }
            }
        }

        //  need pre-check
        if (p_size > N) {
            for (int j = 0; j < p_size; j++) {
                if (p[j] == 'D') {
                    d_count++;
                }
            }
            is_error = d_count > N;

            if (is_error) {
                cout << "error\n";
                continue;
            }
        }

        for (int j = 0; j < p_size; j++) {
            if (p[j] == 'R') {
                front = !front;
            } else {
                if (front) {
                    d.pop_front();
                } else {
                    d.pop_back();
                }
            }
        }

        d_size = d.size();
        cout << "[";
        for (int j = front ? 0 : d_size - 1; front ? j < d_size : j >= 0; j += front ? 1 : -1) {
            cout << d[j] << ((front ? d_size - 1 != j : j > 0) ? "," : "");
        }
        cout << "]\n";
    }

    return 0;
}
