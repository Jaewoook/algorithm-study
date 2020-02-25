#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, M = 0;
    string s;
    map<string, int> dic;

    cin >> N >> M;
    string *str_dic = new string[N];

    for (int i = 0; i < N; i++) {
        cin >> s;
        dic.insert(make_pair(s, i + 1));
        str_dic[i] = s;
    }

    for (int i = 0; i < M; i++) {
        cin >> s;
        if (s[0] >= 'A') {
            cout << dic[s] << "\n";
        } else {
            int n = stoi(s);
            cout << str_dic[n - 1] << "\n";
        }
    }

    delete[] str_dic;
    return 0;
}
