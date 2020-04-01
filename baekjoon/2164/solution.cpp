#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N = 0;
    deque<int> card;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        card.push_back(i);
    }

    while (card.size() > 1) {
        card.pop_front();
        card.push_back(card.front());
        card.pop_front();
    }

    cout << card.back() << "\n";

    return 0;
}
