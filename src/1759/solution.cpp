// 나중에 풀 문제
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void combination(string* result[], int n) {
    for(int i = 0; i < )
}

int main() {
    int L = 0, C = 0;
    string vowel[] = {"a", "e", "i", "o", "u"};
    cin >> L >> C;
    string letter;
    string result[C];
    vector<string> vowels, consonants;
    vowels.reserve(30);
    consonants.reserve(30);

    for(int i = 0; i < C; i++) {
        cin >> letter;
        bool is_vowel = false;
        for (int j = 0; j < 5; j++) {
            if(letter.find(vowel[j]) != string::npos) {
                vowels.push_back(letter);
                is_vowel = true;
            }
        }
        if (!is_vowel) {
            consonants.push_back(letter);
        }
    }

    for (int i = max((int) (L - vowels.size()), 0); i < max(L, (int) vowels.size()); i++) {
        for (int j = 0; j <= i; j++) {
            result[j] = vowels[j]
        }

        for (int j = C - i - 1; j < C; j++) {

        }
    }

    // debug
    cout << "자음: ";
    for(int i = 0; i < consonants.size(); i++) {
        cout << consonants[i] << " ";
    }
    cout << "\n모음: ";

    for(int i = 0; i < vowels.size(); i++) {
        cout << vowels[i] << " ";
    }
    cout << "\n";


    return 0;
}
