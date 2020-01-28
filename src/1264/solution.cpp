#include <iostream>
#include <string>
using namespace std;

int main() {
    int count = 0, size = 0;
    string s;

    getline(cin, s);
    while (s[0] != '#') {
        size = s.size();
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    count++;
            }
        }
        cout << count << "\n";
        getline(cin, s);
        count = 0;
    }

    return 0;
}
