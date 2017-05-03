#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int p[1001];
int pp[1500000];
int main() {
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m) break;
        memset(p, 0, sizeof(p));
        for (int i=0; i<n; i++) scanf("%d",&p[i]);
        sort(p, p+(++n));
        for (int c=0; c<=n; c++) {
            for (int d=0; d<=n; d++) {
                pp[c*n+d]=p[c]+p[d];
            }
        }
        sort(pp, pp+n*n);
        int res=0;
        for (int i=0; i<n*n; i++) {
            int temp = upper_bound(pp,pp+n*n,m-pp[i])-pp-1;
            if (pp[temp]+pp[i]<=m) res = max(res, pp[temp]+pp[i]);
        }
        printf("%d\n",res);
    }
}
