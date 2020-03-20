#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const char VOWELS[] = {'a', 'e', 'i', 'o', 'u'};

void dfs(char letter, vector<char> &letters, vector<char> &pw, int L, int consonant_count, int vowel_count) {
    vector<char>::iterator iter = find(letters.begin(), letters.end(), letter);
    if (L == pw.size()) {
        if (consonant_count >= 2 && vowel_count >= 1) {
            for (int i = 0; i < L; i++) {
                cout << pw[i];
            }
            cout << "\n";
        }
    } else {
        for (; iter != letters.end(); iter++) {
            pw.push_back(*iter);
            bool is_vowel = false;
            for (int i = 0; i < 5; i++) {
                if (VOWELS[i] == *iter) {
                    is_vowel = true;
                    break;
                }
            }
            if (is_vowel) {
                vowel_count++;
            } else {
                consonant_count++;
            }

            dfs(*(iter + 1), letters, pw, L, consonant_count, vowel_count);
            pw.pop_back();
            if (is_vowel) {
                vowel_count--;
            } else {
                consonant_count--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int L = 0, C = 0;
    int vowels = 0, consonants = 0;
    cin >> L >> C;
    vector<char> letters(C), password;
    for (int i = 0; i < C; i++) {
        cin >> letters[i];
    }
    sort(letters.begin(), letters.end());

    dfs(letters[0], letters, password, L, 0, 0);

    return 0;
}
