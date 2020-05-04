#include <iostream>
#include <string>
#include <map>
using namespace std;

int find_root_friend(int n, int *net) {
    if (net[n] != n) {
        return net[n] = find_root_friend(net[n], net);
    }
    return n;
}

void union_network(int a, int b, int *net, int *net_count) {
    a = find_root_friend(a, net);
    b = find_root_friend(b, net);
    if (a == b) {
        return;
    } else if (a < b) {
        if (net[b] != b) {
            union_network(net[b], a, net, net_count);
        }
        net[b] = a;
        net_count[a] += net_count[b];
    } else {
        if (net[a] != a) {
            union_network(net[a], b, net, net_count);
        }
        net[a] = b;
        net_count[b] += net_count[a];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 0, F = 0, count = 0;
    string name1, name2;
    map<string, int> network;

    cin >> T;
    while (T--) {
        cin >> F;
        int *net = new int[F * 2];
        int *net_count = new int[F * 2];
        for (int i = 0; i < F * 2; i++) {
            net[i] = i;
            net_count[i] = 1;
        }
        network.clear();
        count = 0;

        while (F--) {
            cin >> name1 >> name2;
            if (network.count(name1) == 0) {
                network[name1] = count++;
            }
            if (network.count(name2) == 0) {
                network[name2] = count++;
            }
            union_network(network[name1], network[name2], net, net_count);
            cout << net_count[find_root_friend(network[name1], net)] << "\n";
        }

        delete[] net;
        delete[] net_count;
    }
    return 0;
}
