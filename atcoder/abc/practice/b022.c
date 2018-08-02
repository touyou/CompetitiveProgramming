#include <stdio.h>

int main() {
    int N;
    int A[100024];
    scanf("%d", &N);
    for (int i = 0; i < 100024; i++) A[i] = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        if (A[x] != 0) cnt++;
        A[x] = 1;
    }
    printf("%d\n", cnt);
    return 0;
}
