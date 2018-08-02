#include <stdio.h>

int main() {
    int N, a, b, K;
    int P;
    scanf("%d%d%d%d", &N, &a, &b, &K);
    int cnt[N + 1];
    for (int i = 0; i <= N; i++) cnt[i] = 0;
    cnt[a] = cnt[b] = 1;
    for (int i = 0; i < K; i++) {
        scanf("%d", &P);
        cnt[P]++;
    }
    int flag = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] >= 2) {
            flag = 1;
            break;
        }
    }
    puts(flag ? "NO" : "YES");
    return 0;
}
