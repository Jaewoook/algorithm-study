#include <iostream>
#include <string>
using namespace std;

bool check_no(string card_no)
{
    int size = card_no.size();
    bool x2 = false;
    int n, checksum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        n = (card_no[i] - '0') * (x2 ? 2 : 1);
        checksum += n >= 10 ? n - 9 : n;
        x2 = !x2;
    }
    return checksum % 10 == 0;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    string card_no;
    cin >> T;
    while (T--)
    {
        cin >> card_no;
        cout << (check_no(card_no) ? 'T' : 'F') << "\n";
    }

    return 0;
}
