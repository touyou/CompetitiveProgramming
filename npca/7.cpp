#include <cstdio>
int n, m, l;
int t[1000], b[1000];
int main() {
    scanf("%d%d%d",&n,&m,&l);
    for (int i=0; i<n; i++) scanf("%d",&t[i]);
    for (int i=0; i<m; i++) scanf("%d",&b[i]);
    int res=0, flag=0;
    for (int i=0; i<m; i++) {
        if (flag) {
            b[i]-=l;
            flag=0;
        }
        while (b[i]>0) {
            if (b[i]>=t[res]) {
                b[i]-=t[res];
                res++;
            } else {
                t[res]-=b[i];
                flag=1;
                break;
            }
            if (res==n) break;
        }
        if (res==n) break;
    }
    printf("%d\n",res);
}
