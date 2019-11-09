#include <cstdio>
#include <algorithm>
using namespace std;
int par[2000], rank[2000];
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
        return par[x]=find(par[x]);
    }
}
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a==b) return;
    if (rank[a]<rank[b]) {
        par[a]=b;
    } else {
        par[b]=a;
        if (rank[a]==rank[b]) rank[a]++;
    }
}
bool same(int a, int b) {
    return find(a)==find(b);
}
struct edge { int u, v, cost; };
bool comp(const edge& a, const edge& b) {
    return a.cost<b.cost;
}
edge es[10000];
int N, M;
int main() {
    scanf("%d%d",&N,&M);
    for (int i=0; i<M; i++) scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
    sort(es, es+M, comp);
    init(N);
    int res=0;
    for (int i=0; i<M; i++) {
        edge e=es[i];
        if (!same(e.u,e.v)) {
            unite(e.u,e.v);
            res=max(res,e.cost);
        }
    }
    printf("%d\n",res);
}
