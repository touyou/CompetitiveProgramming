#include <cstdio>
int main()
{
    int n;
    while (scanf("%d",&n)&&n!=0) {
        int maxP,maxD=0,p,d1,d2;
        for (int i=0; i<n; i++) {
            scanf("%d%d%d",&p,&d1,&d2);
            if (maxD<d1+d2) {
                maxP=p;
                maxD=d1+d2;
            }
        }
        printf("%d %d\n",maxP,maxD);
    }
}

