#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string sentence, buffer;
    int size = 0, max = 0;
    int alphabet[26] = {0, };
    while (!cin.eof()) {
        getline(cin, buffer);
        sentence += buffer;
    }

    size = sentence.size();
    for (int i = 0; i < size; i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            alphabet[sentence[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (max < alphabet[i]) {
            max = alphabet[i];
        }
    }
    for (int i = 0; i < 26; i++) {
        if (max == alphabet[i]) {
            cout << (char) (i + 'a');
        }
    }
    cout << "\n";

    return 0;
}
