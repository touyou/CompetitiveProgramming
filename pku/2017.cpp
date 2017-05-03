#include <cstdio>
int main()
{
    int n, s, t, old_t;
    while (scanf("%d",&n)&&n!=-1) {
        old_t = 0;
        int res = 0;
        for (int i=0; i<n; i++) {
            scanf("%d%d",&s,&t);
            res += s*(t-old_t);
            old_t = t;
        }
        printf("%d miles\n",res);
    }
}

