#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct unionfind {
    int par[20001], rank[20001];
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
struct edge { int u, v, cost; };
bool comp(const edge& a, const edge& b) { return a.cost<b.cost; }
int n,m,r;
edge es[50000];
int main() {
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        scanf("%d%d%d",&n,&m,&r);
        for (int i=0; i<r; i++) {
            int x, y, d; scanf("%d%d%d",&x,&y,&d);
            es[i]=(edge){x,y+n,-1*d};
        }
        unionfind uf(n+m);
        sort(es, es+r, comp);
        ll res=10000*(n+m);
        for (int i=0; i<r; i++) {
            edge e=es[i];
//            printf("%d %d\n",e.u,e.v);
            if (!uf.same(e.u,e.v)) {
                uf.unite(e.u,e.v);
                res+=e.cost;
            }
        }
        printf("%lld\n",res);
    }
}
