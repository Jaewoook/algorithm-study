#include <iostream>

using namespace std;

int main() {
    int T = 0, W = 0, H = 0, N = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> H >> W >> N;
        int room = (N - 1) / H + 1;
        int floor = N - (room - 1) * H;
        cout << floor << room / 10 << room % 10 << "\n";
    }

    return 0;
}
