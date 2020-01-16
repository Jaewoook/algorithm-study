#include <iostream>

using namespace std;

int main() {
    long A = 0, B = 0, C = 0;
    cin >> A >> B >> C;

    if (B >= C) {
        cout << -1 << "\n";
    } else {
        // 손익분기점 구하는 공식
        // 고정비용 / 마진 + 1 = 물건의 갯수
        cout << A / (C - B) + 1 << "\n";
    }

    return 0;
}
