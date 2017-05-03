#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
using namespace std;
typedef pair<int, int> P;
struct edge { int to, cost; };
vector<edge> G[3000];
int mind[3000];
int d[3000];
int n, m, k;
void dijkstra(int s) {
    fill(d, d+n, INT_MAX);
    d[s]=0;
    priority_queue<P, vector<P>, greater<P> > que;
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
    for (int i=0; i<n; i++) mind[i]=min(mind[i],d[i]);
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    fill(mind, mind+n, INT_MAX);
    for (int i=0; i<m; i++) {
        int a, b, l; scanf("%d%d%d",&a,&b,&l);
        G[a-1].push_back((edge){b-1,l});
        G[b-1].push_back((edge){a-1,l});
    }
    for (int i=0; i<k; i++) {
        int s; scanf("%d",&s);
        dijkstra(s-1);
    }
    int res=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<G[i].size(); j++) {
            edge e=G[i][j];
            res=max(res,(mind[i]+mind[e.to]+e.cost+1)/2);
        }
    }
    printf("%d\n",res);
}
