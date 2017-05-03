#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
using namespace std;
struct edge {
    int to, cost;
    edge(int _to, int _cost) { to=_to; cost=_cost; }
};
typedef pair<int, int> P;
typedef long long ll;
void solve(int f, int t, vector<edge> *G, int n) {
    priority_queue<P, vector<P>, greater<P> > que;
    ll d[n];
    fill(d, d+n, LLONG_MAX);
    d[f-1]=0;
    que.push(P(0,f-1));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v]<p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e=G[v][i];
            if (d[e.to]>d[v]+e.cost) {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    if (d[t-1]==LLONG_MAX) puts("-1");
    else printf("%lld\n",d[t-1]);
}
int main() {
    int n, k;
    while (scanf("%d%d",&n,&k)) {
        if (!n&&!k) break;
        vector<edge> G[n];
        for (int i=0; i<k; i++) {
            int s; scanf("%d",&s);
            if (s) {
                int x, y, cost;
                scanf("%d%d%d",&x,&y,&cost);
                G[x-1].push_back(edge(y-1,cost));
                G[y-1].push_back(edge(x-1,cost));
            } else {
                int f, t; scanf("%d%d",&f,&t);
                solve(f,t,G,n);
            }
        }
    }
}
