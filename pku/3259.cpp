#include <cstdio>
#include <cstring>
struct edge { int from, to, cost; };
const int INF=10000*2500+1;
int f, n, m, w;
int total;
int d[505];
edge es[5100];
bool solve() {
    for (int i=0; i<=n; i++) d[i]=INF;
    d[1]=0;
    for (int i=1; i<n; i++) {
        for (int j=0; j<total; j++) {
            edge e=es[j];
            if (d[e.to]>d[e.from]+e.cost) {
                d[e.to]=d[e.from]+e.cost;
            }
        }
    }
    for (int i=0; i<total; i++) {
        if (d[es[i].to]>d[es[i].from]+es[i].cost) return true;
    }
    return false;
}
int main() {
    scanf("%d",&f);
    for (int ix=0; ix<f; ix++) {
        scanf("%d%d%d",&n,&m,&w);
        total=0;
        for (int i=0; i<m; i++) {
            scanf("%d%d%d",&es[total].from,&es[total].to,&es[total].cost);
            es[total+1].to=es[total].from;
            es[total+1].from=es[total].to;
            es[total+1].cost=es[total].cost;
            total+=2;
        }
        for (int i=0; i<w; i++) {
            int s, e, t; scanf("%d%d%d",&s,&e,&t);
            es[total].from=s;
            es[total].to=e;
            es[total].cost=t*(-1);
            total++;
        }
        if (solve()) puts("YES");
        else puts("NO");
    }
}
