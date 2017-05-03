/*--- Djkstra
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
struct edge {
    int to, cost;
}
int d[MAX_E+1];
vector<edge> G[MAX_E];
int V, E;
void djkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+E, INF);
    d[s]=0;
    que.push(P(0,s));
    while (!que.empty()) {
        P p=que.top(); que.pop();
        int v=p.second;
        if (d[v]<p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e=G[v][i];
            if (d[e.to]>d[v]+e.cost) {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
---*/
/*--- Union-Find
#include <cstdio>
int par[MAX_N], rank[MAX_N];
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
---*/
/*--- Kruskal
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge {
    int u, v, cost;
}
bool comp(const edge& e1, const edge& e2) {
    return e1.cost<e2.cost;
}
edge es[MAX_V];
int V;
int kruskal() {
    sort(es, es+V, comp);
    int res=0;
    for (int i=0; i<V; i++) {
        edge e=es[i];
        if (!same(e.u,e.v)) {
            unite(e.u, e.v);
            res+=e.cost;
        }
    }
    return res;
}
---*/
/*--- Warshall-Floyd
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int d[MAX_N][MAX_N];
void warshall-floyd() {
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
---*/
/*--- Segment Tree
#include <cstdio>
#include <climits>
const int MAX_N=1<<17;
int n, seg[2*MAX_N-1];
void init(int n_) {
    n=1;
    while (n<n_) n*=2;
    for (int i=0; i<2*n-1; i++) seg[i]=INT_MAX;
}
void update(int k, int a) {
    k += n-1;
    seg[k]=a;
    while (k>1) {
        k=(k-1)/2;
        seg[k]=min(seg[2*k+1], seg[2*k+2]);
    }
}
int query(int a, int b, int k, int l, int r) {
    if (r<=a||b<=l) return INT_MAX;
    if (a<=l&&r<=b) return set[k];
    else {
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return min(vl, vr);
    }
}
---*/
