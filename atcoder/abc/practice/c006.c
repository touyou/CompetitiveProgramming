#include <stdio.h>

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) {
        int leg = m - i * 2;
        int num = n - i;
        if ((leg - 3 * num) >= 0 && (4 * num - leg) >= 0) {
            printf("%d %d %d\n", i, 4 * num - leg, leg - 3 * num);
            return 0;
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}
