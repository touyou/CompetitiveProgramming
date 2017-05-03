#include <cstdio>
#include <algorithm>
using namespace std;
#define EPS 0.0000001
int main() {
    int t; scanf("%d",&t);
    double max_v=0.0;
    for (int i=0; i<t; i++) {
        double v=0.0, r=1.0;
        int n, m; scanf("%d%d",&n,&m);
        for (int j=0; j<m; j++) {
            int vj;
            double rj;
            scanf("%d%lf",&vj,&rj);
            v+=vj*rj;
            r-=rj;
        }
        double x=1.0, y=0.0;
        for (int j=0; j<100; j++) {
            y+=v*x;
            x*=r;
        }
        max_v=max(max_v,y);
    }
    int p, q; scanf("%d%d",&p,&q);
    double boss=0.0, br=1.0;
    for (int i=0; i<q; i++) {
        int vi;
        double ri;
        scanf("%d%lf",&vi,&ri);
        boss+=vi*ri;
        br-=ri;
    }
    double bx=1.0, by=0.0;
    for (int i=0; i<100; i++) {
        by+=boss*bx;
        bx*=br;
    }
    if (by+EPS<=max_v) puts("YES");
    else puts("NO");
}
