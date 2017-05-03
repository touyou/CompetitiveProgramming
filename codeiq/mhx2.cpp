#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
struct edge { int to; ll cost; };
typedef pair<ll, int> P;
ll INF = 100000000000;
int m[300][300]; // map
vector<edge> G[90000];
vector<int> qlist;
ll d[90000], x[16][16];
ll dp[1<<16][16];
int V, H, W, qrd, n; string str;
void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i=0; i< G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void solve() {
    for (int S=0; S < 1 << n; S++) {
        fill(dp[S], dp[S] + n, INF);
    }
    dp[(1 << n) - 1][0] = 0;
    for (int S = (1 << n) - 2; S >= 0; S--) {
        for (int v = 0; v < n; v++) {
            for (int u = 0; u < n; u++) {
                if (!(S >> u & 1)) {
                    if (x[v][u] != INF)
                        dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + x[v][u]);
                }
            }
        }
    }
}

edge make_edge(int dist, int i, int j) {
    edge e;
    e.to = i * W + j;
    switch (dist) {
    case 0:
        e.cost = 3;
        break;
    case 1:
        e.cost = 11;
        break;
    case -1:
        e.cost = 2;
        break;
    default:
        e.cost = INF;
        break;
    }
    return e;
}

int main() {
    scanf("%d%d", &H, &W);
    for (int i=0; i<H; i++) {
        cin>>str;
        for (int j=0; j<W; j++) {
            m[i][j] = str[j] - '0';
        }
    }
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            int ac = i * W + j;
            if (i != 0)
                G[ac].push_back(make_edge(m[i-1][j]-m[i][j],i-1,j));
            if (j != 0)
                G[ac].push_back(make_edge(m[i][j-1]-m[i][j],i,j-1));
            if (i+1 < H)
                G[ac].push_back(make_edge(m[i+1][j]-m[i][j],i+1,j));
            if (j+1 < W)
                G[ac].push_back(make_edge(m[i][j+1]-m[i][j],i,j+1));
            qrd = max(qrd, m[i][j]);
        }
    }
    V = H * W;
    // dijkstra -> 巡回セールスマン
    // まずグラフをつくらねば
    qlist.push_back(0);
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            int ac = i * W + j;
            if (m[i][j] == qrd) qlist.push_back(ac);
        }
    }
    n = qlist.size();
    for (int i=0; i<n; i++) {
        dijkstra(qlist[i]);
        for (int j=0; j<n; j++) {
            x[i][j] = d[qlist[j]];
            // printf("%lld ",x[i][j]);
        }
    }
    solve();
    printf("%lld\n", dp[0][0]);
}

