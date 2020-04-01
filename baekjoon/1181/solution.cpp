#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    int a_size = a.size();
    int b_size = b.size();

    if (a_size == b_size) {
        return a < b;
    } else {
        return a_size < b_size;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0;
    string prev;
    cin >> N;

    string* dic = new string[N];
    for (int i = 0; i < N; i++) {
        cin >> dic[i];
    }
    sort(dic, dic + N, compare);

    for (int i = 0; i < N; i++) {
        if (prev != dic[i]) {
            cout << dic[i] << "\n";
            prev = dic[i];
        }
    }

    return 0;
}
