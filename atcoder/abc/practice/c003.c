#include <stdio.h>
#include <stdlib.h>

int asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
    int N, K;
    int R[128];
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", R + i);
    qsort(R, N, sizeof(int), asc);
    double rate = 0;
    for (int i = N - K; i < N; i++) rate = (rate + (double)R[i]) / 2.0;
    printf("%lf\n", rate);
    return 0;
}
