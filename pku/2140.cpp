#include <cstdio>

int main()
{
    int N, res = 1;
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int num = i;
        for (int j = i + 1; j <= N; j++) {
            if (num > N) break;
            if (num == N) {
                res++;
                break;
            }
            num += j;
        }
    }
    printf("%d\n", res);
}

