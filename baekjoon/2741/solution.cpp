#include <stdio.h>

//  cin cout 은 느려서 scanf printf 로 대체
int main() {
    int row = 0;
    scanf("%d", &row);

    for (int i = 1; i <= row; i++) {
        printf("%d\n", i);
    }

    return 0;
}
