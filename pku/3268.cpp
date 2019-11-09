#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
struct edge {int to, cost;};
const int INF=100000;
int n, m, x, a, b, t;
vector<edge> G[1000];
int d[1000];
int djkstra(int s, int g) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+n, INF);
    d[s]=0;
    que.push(P(0,s));
    while (!que.empty()) {
        P p=que.top(); que.pop();
        int v=p.second;
        if (d[v]<p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    return d[g];
}
int main() {
    scanf("%d%d%d",&n,&m,&x);
    for (int i=0; i<m; i++) {
        scanf("%d%d%d",&a,&b,&t);
        G[a-1].push_back((edge){b-1,t});
    }
    int res=0;
    for (int i=0; i<n; i++) {
        res=max(res,djkstra(i,x-1)+djkstra(x-1,i));
    }
    printf("%d\n",res);
}
