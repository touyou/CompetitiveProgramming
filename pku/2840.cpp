#include <cstdio>

int main()
{
    int T,H,M;
    scanf("%d",&T);
    for (int i=0; i<T; i++) {
        scanf("%d%*c%d",&H,&M);
        if (M != 0) {
            printf("0\n");
            continue;
        }
        int res = H + 12;
        if (res > 24) res -= 24;
        printf("%d\n",res);
    }
}

