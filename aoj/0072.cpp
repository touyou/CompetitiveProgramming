#include <cstdio>
#include <algorithm>
using namespace std;
struct edge { int u, v, cost; };
struct unionfind {
    int par[100], rank[100];
    unionfind(int n) {
        for (int i=0; i<n; i++) {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x) {
        if (x==par[x]) {
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
bool comp(const edge& a, const edge& b) {
    return a.cost<b.cost;
}
edge es[10000];
int main() {
    int n, m;
    while (scanf("%d",&n)) {
        if (!n) break;
        scanf("%d",&m);
        unionfind uf(n);
        for (int i=0; i<m; i++) {
            int a, b, d; scanf("%d%*c%d%*c%d",&a,&b,&d);
            es[i]=(edge){a,b,d/100-1};
        }
        sort(es, es+m, comp);
        int res=0;
        for (int i=0; i<m; i++) {
            edge e=es[i];
            if (!uf.same(e.u,e.v)) {
                uf.unite(e.u,e.v);
                res+=e.cost;
            }
        }
        printf("%d\n",res);
    }
}
