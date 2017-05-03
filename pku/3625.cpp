#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
struct unionfind {
    int par[1000], rank[1000];
    unionfind(int n) {
        for (int i=0; i<n; i++) {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x) {
        if (par[x]==x) {
            return x;
        } else {
            return par[x]=find(par[x]);
        }
    }
    void unite(int x, int y) {
        x=find(x);
        y=find(y);
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
};
struct edge {
    int u, v;
    double cost;
};
bool comp(const edge& e1, const edge& e2) {
    return e1.cost<e2.cost;
}
int n,m;
ll x[1000],y[1000];
edge es[1000000];
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%lld%lld",&x[i],&y[i]);
    }
    int edn=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            es[edn].u=i;
            es[edn].v=j;
            es[edn].cost=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            edn++;
        }
    }
    unionfind uf(n);
    for (int i=0; i<m; i++) {
        int a, b; scanf("%d%d",&a,&b);
        uf.unite(a-1,b-1);
    }
    sort(es, es+edn, comp);
    double res=0.0;
    for (int i=0; i<edn; i++) {
        edge e=es[i];
        if (!uf.same(e.u,e.v)) {
            uf.unite(e.u,e.v);
//            printf("%d %d %.2f\n",e.u,e.v,e.cost);
            res+=e.cost;
        }
    }
    printf("%.2f\n",res);
}
