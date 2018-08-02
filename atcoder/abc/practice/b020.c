#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int res;
    if (b < 10) {
        res = b + a * 10;
    } else if (b < 100) {
        res = b + a * 100;
    } else {
        res = b + a * 1000;
    }
    printf("%d\n", res * 2);
    return 0;
}
