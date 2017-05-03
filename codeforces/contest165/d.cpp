#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
#define inf 10000000
using namespace std;
typedef pair<int, int> P;
struct edge {
    int from, to, cost;
    bool flag;
};
int n, m;
edge es[100000];
vector<edge*> G[100000];
int d[100000];
int dijkstra(int a, int b) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+n, inf);
    d[a]=0;
    que.push(P(0,a));
    while (!que.empty()) {
        P p=que.top(); que.pop();
        int v=p.second;
        if (d[v]<p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e=*G[v][i];
            if (e.to==v) swap(e.to, e.from);
            if (d[e.to]>d[v]+e.cost&&e.flag) {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    if (d[b]==inf) return -1;
    else return d[b];
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int v, u; scanf("%d%d",&v,&u);
        es[i]=(edge){v-1,u-1,1,true};
        G[v-1].push_back(&es[i]);
        G[u-1].push_back(&es[i]);
    }
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
        int t; scanf("%d",&t);
        if (t==1) {
            int id; scanf("%d",&id);
            es[id-1].flag=true;
        } else if (t==2) {
            int id; scanf("%d",&id);
            es[id-1].flag=false;
        } else if (t==3) {
            int a, b; scanf("%d%d",&a,&b);
            printf("%d\n",dijkstra(a-1,b-1));
        }
    }
}
