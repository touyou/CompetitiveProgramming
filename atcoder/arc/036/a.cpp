#include <cstdio>
int n, k, t[3], ans, sum;
int main() {
    ans = -1;
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%d", &t[i%3]);
        sum = t[0] + t[1] + t[2];
        if (i > 1 && sum < k && ans == -1) ans = i + 1;
    }
    printf("%d\n", ans);
}
