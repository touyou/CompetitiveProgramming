#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int par[10000];
int rank[10000];
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

struct point { int x, y; };
struct edge {
    int u, v;
    double cost;
};
bool comp(const edge& e1, const edge& e2) {
    return e1.cost>e2.cost;
}
double dist(point p1, point p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point p[10000];
vector<edge> es;
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    init(n);
    for (int i=0; i<n; i++) scanf("%d%d",&p[i].x,&p[i].y);
    double all=0.0;
    for (int i=0; i<m; i++) {
        int s, e; scanf("%d%d",&s,&e);
        edge ne=(edge){s-1,e-1,dist(p[s-1],p[e-1])};
        es.push_back(ne);
        all+=ne.cost;
    }
    sort(es.begin(), es.end(), comp);
    double res=0.0;
    for (int i=0; i<m; i++) {
        edge e=es[i];
        if (!same(e.u,e.v)) {
            unite(e.u, e.v);
            res+=e.cost;
        }
    }
    printf("%.3f\n",all-res);
}
