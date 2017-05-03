#include <cstdio>
int main()
{
    int A, B, C, D;
    while (scanf("%d%d%d%d", &A, &B, &C, &D)) {
        if (A == 0 && B == 0 && C == 0 && D == 0) break;
        if (A > B) {
            int temp = A;
            A = B;
            B = temp;
        }
        if (C > D) {
            int temp = C;
            C = D;
            D = temp;
        }
        if (A <= C && B <= D) {
            printf("100%%\n");
            continue;
        }
        int res;
        if (C * 100 / A >= D * 100 / B) res = D * 100 / B;
        else res = C * 100 / A;
        printf("%d%%\n", res);
    }
}

