#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int n;
    int value, max_value = numeric_limits<int>::min();
    cin >> n;
    int *cards = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    sort(cards, cards + n);

    max_value = max(max_value, cards[n - 1] * cards[n - 2]);
    max_value = max(max_value, cards[0] * cards[1]);
    max_value = max(max_value, cards[n - 1] * cards[n - 2] * cards[n - 3]);
    max_value = max(max_value, cards[n - 1] * cards[n - 2] * cards[0]);
    max_value = max(max_value, cards[n - 1] * cards[0] * cards[1]);
    max_value = max(max_value, cards[0] * cards[1] * cards[2]);

    cout << max_value << "\n";

    delete[] cards;
    return 0;
}
