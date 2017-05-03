#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
struct unionfind {
    int par[100000], rank[100000];
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
    int cnt(int n) {
        set<int> p;
        for (int i=0; i<n; i++) {
            p.insert(find(i));
        }
        return p.size();
    }
};
struct edge { int u, v, cost; };
bool comp(const edge& a, const edge& b) {
    return a.cost<b.cost;
}
int n, m, k;
edge road[100000];
int main() {
    scanf("%d%d%d",&n,&m,&k);
    unionfind uf(n);
    for (int i=0; i<m; i++) {
        int a, b, c; scanf("%d%d%d",&a,&b,&c);
        road[i]=(edge){a-1,b-1,c};
    }
    sort(road,road+m,comp);
    int res=0;
    if (k==1) {
        for (int i=0; i<m; i++) {
            if (!uf.same(road[i].u,road[i].v)) {
                uf.unite(road[i].u,road[i].v);
                res+=road[i].cost;
            }
        }
    } else {
        for (int i=0; i<m; i++) {
            if (!uf.same(road[i].u,road[i].v)) {
                uf.unite(road[i].u,road[i].v);
                res+=road[i].cost;
                if (uf.cnt(n)==k) break;
            }
        }
    }
    printf("%d\n",res);
}
