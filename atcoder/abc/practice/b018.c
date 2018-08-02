#include <stdio.h>

int main() {
    char S[120], tmp[120];
    int N, l, r;
    scanf("%s%d", S, &N);
    for (int c = 0; c < N; c++) {
        scanf("%d%d", &l, &r);
        l--; r--;
        for (int i = l; i <= r; i++) {
            tmp[r - (i - l)] = S[i];
        }
        for (int i = l; i <= r; i++) {
            S[i] = tmp[i];
        }
    }
    printf("%s\n", S);
    return 0;
}
