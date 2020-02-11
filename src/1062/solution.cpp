//  TODO
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, K = 0, size = 0, count = 0;
    string s;

    cin >> N >> K;
    string* words = new string[N];

    for (int i = 0; i < N; i++) {
        cin >> s;
        size = s.size();
        for (int j = 0; j < size; j++) {
            if (s[j] != 'a' && s[j] != 'n' && s[j] != 't' && s[j] != 'i' && s[j] != 'c' && words[i].find(s[j]) == string::npos) {
                words[i] += s[j];
            }
        }
    }

    s = "antic";
    int s_size = 5;
    K -= 5;
    if (K < 0) {
        count = 0;
    } else {
        for (int i = 0; i < N; i++) {
            size = words[i].size();
            if (size <= K) {
                for (int j = 0; j < size; j++) {
                    if (s.find(words[i][j]) == string::npos) {
                        s_size++;
                    }
                }
                if (s_size - 5 <= K) {
                    s += words[i];
                    count++;
                } else {
                    s_size - size;
                }
            }
        }
    }

    cout << count << "\n";

    delete[] words;
    return 0;
}
