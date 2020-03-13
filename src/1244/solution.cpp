#include <iostream>
#include <vector>
#define MAN 1
#define WOMAN 2
using namespace std;;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, tmp = 0, tmp2 = 0, gender = 0;
    vector<bool> rooms;
    rooms.push_back(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        rooms.push_back(tmp);
    }

    cin >> M;
    while (M--) {
        cin >> gender >> tmp;

        switch (gender) {
            case MAN:
                for (int i = tmp; i <= N; i += tmp) {
                    rooms[i] = !rooms[i];
                }
                break;
            case WOMAN:
                rooms[tmp] = !rooms[tmp];
                tmp2 = 1;
                while (tmp + tmp2 <= N && tmp - tmp2 > 0) {
                    if (rooms[tmp + tmp2] != rooms[tmp - tmp2]) {
                        break;
                    }
                    rooms[tmp + tmp2] = !rooms[tmp + tmp2];
                    rooms[tmp - tmp2] = !rooms[tmp - tmp2];
                    tmp2++;
                }
                break;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << rooms[i] << (i % 20 == 0 ? "\n" : " ");
    }

    return 0;
}
