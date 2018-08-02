#include <stdio.h>

int main() {
    int T, N, M;
    int A[128], B[128];
    for (int i = 0; i < 128; i++) A[i] = 10000;
    scanf("%d%d", &T, &N);
    for (int i = 0; i < N; i++) scanf("%d", A + i);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) scanf("%d", B + i);
    int l = 0, r = 0;
    for (int i = 0; i < M; i++) {
        while (l < N && A[l] < B[i] - T) {
            l++;
        }
        while (r < N && A[r] <= B[i]) {
            r++;
        }
        if (r - l >= 1) {
            l++;
        } else {
            puts("no");
            return 0;
        }
    }
    puts("yes");
    return 0;
}
