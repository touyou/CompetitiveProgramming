#include <stdio.h>
#include <math.h>
int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int normal_diff = abs(a - b);
    int irr_diff;
    if (a < b) {
        irr_diff = 9 - b + a + 1;
    } else {
        irr_diff = 9 - a + b + 1;
    }
    printf("%d\n", min(normal_diff, irr_diff));
    return 0;
}

