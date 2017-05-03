#include <cstdio>

char sum[1000005];
int N, a, b, x;

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d%d", &a, &b);
        sum[i] = '0' + a + b;
    }
    for (int i=N-1; i>=0; i--) {
        if (sum[i] > '9') {
            sum[i] -= 10;
            sum[i-1]++;
        }
    }
    fwrite(sum, 1, N, stdout); puts("");
}

