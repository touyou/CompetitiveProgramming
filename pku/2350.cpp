#include <cstdio>

int main()
{
    int C, N;
    scanf("%d", &C);
    for (int ix = 0; ix < C; ix++) {
        scanf("%d", &N);
        int sum = 0;
        int std[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &std[i]);
            sum += std[i];
        }
        int res = 0;
        for (int i = 0; i < N; i++)
            if (std[i] > sum / N) res++;
        float ans = (float)res * 100 / (float)N;
        printf("%.3f%%\n", ans);
    }
}
