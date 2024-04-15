// Lv. 1 - 문자열을 정수로 바꾸기

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int coef = 1;
    int result = 0;
    int s_size = s.size();

    for (int i = 0; i < s_size; i++) {
        if (s[i] == '-') {
            coef = -1;
        }

        int digit = s[i] - '0';
        if (digit < 0 || digit > 9) {
            continue;
        }
        result *= 10;
        result += digit;
    }

    return result * coef;
}
