#include <cstdio>
#include <cstring>
#define LIM 10000
int n, res, b[1000000], nb[1000000];
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) scanf("%d",&b[i]);
        for (res=0; res<=LIM+1; res++) {
            bool flag=true;
            if (b[0]==1) {
                for (int i=1; i<n; i++) {
                    if (b[i]-b[i-1]!=1) {
                        flag=false;
                        break;
                    }
                }
            } else {
                flag=false;
            }
            if (flag) break;
            for (int i=0; i<n; i++) b[i]--;
            int x=0;
            for (int i=0; i<n; i++) {
                if (!b[i]) continue;
                nb[x++] = b[i];
            }
            nb[x++] = n;
            n = x;
            for (int i=0; i<n; i++) {
                b[i] = nb[i];
            }
        }
        if (res>LIM) puts("-1");
        else printf("%d\n",res);
    }
}
