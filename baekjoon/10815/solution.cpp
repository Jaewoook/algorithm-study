#include <iostream>
using namespace std;

#define SIZE 20000001

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, M = 0, num = 0;
    int *arr = new int[SIZE];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        arr[num + 10000000] = true;
    }
    cin >> M;
    while (M--) {
        cin >> num;
        cout << arr[num + 10000000] << " ";
    }

    delete[] arr;
    return 0;
}
