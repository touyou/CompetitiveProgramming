#include <cstdio>
#include <algorithm>
using namespace std;
struct unionfind {
    int par[100], rank[100];
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
    int u, v, cost;
    edge(){}
    edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};
bool comp(const edge& e1, const edge& e2) {
    return e1.cost<e2.cost;
}
int main() {
    int n, m;
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m) break;
        unionfind uf(n);
        edge bridge[m];
        for (int i=0; i<m; i++) {
            int a, b, cost; scanf("%d%d%d",&a,&b,&cost);
            bridge[i]=edge(a,b,cost);
        }
        sort(bridge,bridge+m,comp);
        int res=0;
        for (int i=0; i<m; i++) {
            edge e=bridge[i];
            if (!uf.same(e.u,e.v)) {
                uf.unite(e.u,e.v);
                res+=e.cost;
            }
        }
        printf("%d\n",res);
    }
}
