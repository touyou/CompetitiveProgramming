#include <cstdio>
int n, m;
int main() {
    scanf("%d%d",&n,&m);
    int res=0;
    for (int i=1; i<=m; i++) {
        res+=(m/i-(n-1)/i);
    }
    printf("%d\n",res);
}
