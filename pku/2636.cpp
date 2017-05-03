#include <cstdio>

int main()
{
    int N,K;
    scanf("%d",&N);
    for (int ix=0; ix<N; ix++) {
        scanf("%d",&K);
        int res,temp;
        scanf("%d",&res);
        for (int i=1; i<K; i++) {
            scanf("%d",&temp);
            res+=temp-1;
        }
        printf("%d\n",res);
    }
}

