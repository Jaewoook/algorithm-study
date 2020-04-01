#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
using namespace std;

int main() {
    long long result = 0;
    string s, tmp;
    map<string, string> v;
    v.insert(make_pair("black", "0"));
    v.insert(make_pair("brown", "1"));
    v.insert(make_pair("red", "2"));
    v.insert(make_pair("orange", "3"));
    v.insert(make_pair("yellow", "4"));
    v.insert(make_pair("green", "5"));
    v.insert(make_pair("blue", "6"));
    v.insert(make_pair("violet", "7"));
    v.insert(make_pair("grey", "8"));
    v.insert(make_pair("white", "9"));
    map<string, long long> m;
    m.insert(make_pair("black", 1));
    m.insert(make_pair("brown", 10));
    m.insert(make_pair("red", 100));
    m.insert(make_pair("orange", 1000));
    m.insert(make_pair("yellow", 10000));
    m.insert(make_pair("green", 100000));
    m.insert(make_pair("blue", 1000000));
    m.insert(make_pair("violet", 10000000));
    m.insert(make_pair("grey", 100000000));
    m.insert(make_pair("white", 1000000000));


    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (i != 2) {
            tmp += v[s];
        } else {
            result = stoll(tmp) * m[s];
        }
    }

    cout << result << "\n";

    return 0;
}
