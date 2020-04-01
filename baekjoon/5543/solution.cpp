#include <iostream>
using namespace std;

int main() {
    int price = 0, burger = 2000, beverage = 2000;

    for (int i = 0; i < 5; i++) {
        cin >> price;
        if (i < 3) {
            burger = burger > price ? price : burger;
        } else {
            beverage = beverage > price ? price : beverage;
        }
    }

    cout << burger + beverage - 50 << "\n";
    return 0;
}
