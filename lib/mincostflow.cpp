#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#define max_v 1000000
#define inf INT_MAX/2
struct edge { int to, cap, cost, rev; };
typedef pair<int, int> P;
int V;
vector<edge> G[max_v];
int h[max_v];
int dist[max_v];
int prev[max_v], pree[max_v];   // 直前の頂点と直前の辺
void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
int min_cost_flow(int s, int t, int f) {
    int res=0;
    fill(h, h+V, 0);
    while (f>0) {
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dist, dist+V, inf);
        dist[s]=0;
        que.push(P(0,s));
        while (!que.empty()) {
            P p=que.top(); que.pop();
            int v=p.second;
            if (dist[v]<p.first) continue;
            for (int i=0; i<G[v].size(); i++) {
                edge &e=G[v][i];
                if (e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]) {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prev[e.to]=v;
                    pree[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if (dist[t]==inf) return -1;
        for (int v=0; v<V; v++) h[v]+=dist[v];      // ポテンシャルの更新
        int d=f;
        for (int v=t; v!=s; v=prev[v]) {
            d=min(d,G[prev[v]][pree[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for (int v=t; v!=s; v=prev[v]) {
            edge &e=G[prev[v]][pree[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
