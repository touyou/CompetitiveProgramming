#include <cstdio>
#include <algorithm>
using namespace std;
int par[1000];
int rank[1000];
void init(int n) {
    for (int i=0; i<n; i++) {
        par[i]=i;
        rank[i]=0;
    }
}
int find(int x) {
    if (par[x]==x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) return;
    if (rank[x]<rank[y]) {
        par[x]=y;
    } else {
        par[y]=x;
        if (rank[x]==rank[y]) rank[x]++;
    }
}
bool same(int x, int y) {
    return find(x)==find(y);
}

struct edge { int u, v, cost; };
bool comp(const edge& e1, const edge& e2) {
    return e1.cost > e2.cost;
}

edge es[20000];
int n, m;

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
    sort(es, es+m, comp);
    init(n);
    int res = 0;
    for (int i=0; i<m; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    bool flag=true;
    for (int i=2; i<=n; i++) {
        if (!same(1,i)) {
            flag=false;
            break;
        }
    }
    if (flag) printf("%d\n",res);
    else puts("-1");
}
