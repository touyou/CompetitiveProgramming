#include <cstdio>
int n, m;
int a, b;
int main() {
    scanf("%d%d",&n,&m);
    int res=0;
    for (int i=0; i<n; i++) {
        scanf("%d%d",&a,&b);
        if (a<=m&&m<=b) res++;
    }
    printf("%d\n",res);
}
