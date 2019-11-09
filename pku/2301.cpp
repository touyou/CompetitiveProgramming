#include <cstdio>

int main()
{
    int n, s, d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &s, &d);
        if (s < d || (s + d) % 2 != 0 || (s - d) % 2 != 0) {
            printf("impossible\n");
            continue;
        }
        printf("%d %d\n", (s + d) / 2, (s - d) / 2);
    }
}
