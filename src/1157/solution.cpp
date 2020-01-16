#include <iostream>
#include <string>

using namespace std;

int main() {
    int alphabet[26] = {0, }, maxIndex = 0, count = 0;
    string S;

    cin >> S;

    int size = S.size();
    for (int i = 0; i < size; i++) {
        S[i] = toupper(S[i]);
    }
    for (int i = 0; i < size; i++) {
        alphabet[S[i] - 65]++;
    }
    for (int i = 0; i < 26; i++) {
        if (count < alphabet[i]) {
            count = alphabet[i];
            maxIndex = i;
        } else if (count == alphabet[i]) {
            maxIndex = -1;
        }
    }

    cout << (maxIndex > -1 ? (char) (maxIndex + 65) : '?');

    return 0;
}
