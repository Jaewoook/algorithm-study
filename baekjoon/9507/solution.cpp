#include <iostream>
using namespace std;

int main() {
    long long d[68] = { 1, 1, 2, 4, };
	int t, x = 0;

	for (int i = 4; i < 68; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3] + d[i - 4];
	}

	cin >> t;
	while (t--) {
		cin >> x;
		cout << d[x] << '\n';
	}
	return 0;
}
