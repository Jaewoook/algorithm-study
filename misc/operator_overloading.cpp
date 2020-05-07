#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Hang {
    int coefficient;
    int power;
};

class Polynomial {
public:
    vector<Hang> poly;
    Polynomial operator+(Polynomial &p) {
        Polynomial new_poly;
        vector<Hang> v(p.poly);
        for (vector<Hang>::iterator i = poly.begin(); i != poly.end(); i++) {
            vector<Hang>::iterator j = v.begin();
            Hang hang;
            while (j != v.end()) {
                if ((*i).power == (*j).power) {
                    hang.coefficient = (*i).coefficient + (*j).coefficient;
                    v.erase(j);
                } else {
                    j++;
                }
            }
        }
        while (!v.empty()) {
            poly.push_back(v.front());
            v.erase(v.begin());
        }
        return new_poly;
    }
    friend istream& operator>>(istream &, Polynomial &);
    friend ostream& operator<<(istream &, Polynomial &);
};

istream& operator>>(istream &in, Polynomial &p) {
    string str;
    in >> str;
    int size = str.size();
    int i = 0;
    while (i < size) {
        if (str[i] != '(') {
            break;
        }
        Hang hang;
        hang.coefficient = str[i + 1] - 48;
        if (str[i + 3] == '-') {
            break;
        }
        hang.power = str[i + 3] - 48;
        p.poly.push_back(hang);
        i += 5;
    }
    return in;
}

ostream& operator<<(ostream &out, Polynomial &p) {
    for (vector<Hang>::iterator iter = p.poly.begin(); iter != p.poly.end(); iter++) {
        if ((*iter).coefficient > 1) {
            cout << (*iter).coefficient;
        }
        cout << "x";
        if ((*iter).power > 1) {
            cout << "^" << (*iter).power;
        }
        if (iter + 1 != p.poly.end()) {
            cout << "+";
        }
    }
    return out;
}

int main() {
    Polynomial A, B, C, D;
    int x = 0;
    cin >> A >> B;
    cout << "A(x)= " << A << "\n";
    cout << "B(x)= " << B << "\n";

    cout << "T(x)= " << (A + B) << "\n";
    return 0;
}
