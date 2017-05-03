#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <functional>
using namespace std;
struct edge { 
    int to, cost;
    edge(int _to, int _cost) { to = _to; cost = _cost; }
};
typedef pair<int, int> P;
void solve() {
    int T, N;
    scanf("%d%d",&N,&T);
    vector<edge> G[N];
    int d[N];
    for (int i=0; i<T; i++) {
        int x, y, c1, c2;
        scanf("%d%*c%d%*c%d%*c%d", &x,&y,&c1,&c2);
        G[x-1].push_back(edge(y-1,c1));
        G[y-1].push_back(edge(x-1,c2));	
    }
    int start, goal, gift, cost;
    scanf("%d%*c%d%*c%d%*c%d",&start,&goal,&gift,&cost);
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+N, INT_MAX);
    d[start-1] = 0;
    que.push(P(0,start-1));
    while (!que.empty()) {
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
    int res = gift-cost-d[goal-1];
    fill(d, d+N, INT_MAX);
    d[goal-1] = 0;
    que.push(P(0,goal-1));
    while (!que.empty()) {
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
    printf("%d\n", res-d[start-1]);
}
int main() {
    solve();
}
