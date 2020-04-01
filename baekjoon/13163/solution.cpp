#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, len = 0, j = 0;
    char name[101], godname[100];

    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        memset(godname, 0, 100);
        cin.getline(name, 101);
        len = strlen(name);
        for (j = 0; j < len; j++) {
            if (name[j] == ' ') {
                break;
            }
        }
        for (; j < len; j++) {
            if (name[j] != ' ') {
                godname[strlen(godname)] = name[j];
            }
        }
        cout << "god" << godname << "\n";
    }

    return 0;
}
