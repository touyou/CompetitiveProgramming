#include <cstdio>
#include <cmath>
int main()
{
    int N;
    scanf("%d", &N);
    for (int ix = 0; ix < N; ix++) {
        char dec[32];
        scanf("%s", dec);
        int ip[4];
        for (int i = 0; i < 4; i++) {
            ip[i] = 0;
            for (int j = 0; j < 8; j++) {
                if (dec[i * 8 + j] == 1 + '0') ip[i] += pow(2, 7 - j);
            }
        }
        printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    }
}
