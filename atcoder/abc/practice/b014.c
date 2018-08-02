#include <stdio.h>

int main() {
    int n, X;
    int a[30];
    scanf("%d%d", &n, &X);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (X >> i & 1) val += a[i];
    }
    printf("%d\n", val);
    return 0;
}
