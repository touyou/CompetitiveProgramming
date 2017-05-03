// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1182&lang=jp
// 最初に各区間の料金を計算して料金に対してDijkstraをかける
// 同じ会社でつながる区間は一つにまとめたほうがよい⇒DFS?
#include <bits/stdc++.h>
using namespace std;
// こっからDijkstra
#define inf INT_MAX/2
typedef pair<int, int> P;
struct edge { int to, cost; };
struct Dijkstra {

vector<edge> G[100];
int d[100];
int dijkstra(int st, int go) {
    fill(d, d+100, inf);
    d[st] = 0;
    priority_queue<P, vector<P>, greater<int> > que;
    que.push(P(st, st));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d[go]==inf?-1:d[go];
}

};
// ここまで
int n, m, c, s, g;
int x[10000], y[10000], da[10000], ca[10000];
int pa[20], q[20][52], r[20][52];

int f(int key, int dist) {
    int ret = 0;
    int i;
    for (i=1; i <= pa[key]; i++) {
        if (q[key][i] > dist) break;
        ret += (q[key][i] - q[key][i-1] + 1) * r[key][i];
    }
    if (q[key][i-1] != dist) ret += (dist - q[key][i-2] + 1) * r[key][i-1];
}

int main() {
    while(scanf("%d%d%d%d%d",&n,&m,&c,&s,&g)) {
        if (n==0&&m==0&&c==0&&s==0&&g==0) break;
        for (int i=0; i<m; i++) scanf("%d%d%d%d",&x[i],&y[i],&da[i],&ca[i]);
        for (int i=0; i<c; i++) scanf("%d",&pa[i]);
        for (int i=0; i<c; i++) {
            for (int j=1; j<pa[i]; j++) scanf("%d",&q[i][j]);
            for (int j=1; j<pa[i]; j++) scanf("%d",&r[i][j]);
            q[i][0] = 0; q[i][pa[i]] = inf;
        }

        Dijkstra dik = Dijkstra();
        // エッジ作る
        for (int i=0; i<m; i++) {
            int start = x[i];

        }
    }
}
