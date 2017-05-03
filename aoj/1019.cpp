#include <cstdio>
int n, k, s[100], b[100];
int main() {
    while (scanf("%d%d",&n,&k)) {
        if (!n&&!k) break;
        for (int i=0; i<k; i++) {
            scanf("%d",&s[i]);
            b[i]=0;
        }
        for (int i=0; i<n; i++) for (int j=0; j<k; j++) {
            int x; scanf("%d",&x);
            b[j]+=x;
        }
        bool flag=true;
        for (int i=0; i<k; i++) if (s[i]<b[i]) flag=false;
        if (flag) puts("Yes");
        else puts("No");
    }
}