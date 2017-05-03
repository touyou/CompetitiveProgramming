#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
#define inf LLONG_MAX/2
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge { int to, cost; };
int n, p, k;
vector<edge> G[1000];
ll d[1000];
int prev[1000];
ll dijkstra() {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+n, inf);
    d[0]=0;
    que.push(P(0,0));
    while (!que.empty()) {
        P p=que.top(); que.pop();
        int v=p.second;
        if (d[v]<p.first) break;
        for (int i=0; i<G[v].size(); i++) {
            edge e=G[v][i];
            if (d[e.to]>d[v]+e.cost) {
                d[e.to]=d[v]+e.cost;
                prev[e.to]=v;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    if (d[n-1]==inf) return -1;
    else {
        vector<ll> visit;
        for (int v=n-1; v!=0; v=prev[v]) {
            visit.push_back(G[v][prev[v]].cost);
        }
        sort(visit.rbegin(), visit.rend());
        for (int i=0; i<k; i++) visit[i]=0;
        ll sum=0;
        for (int i=0; i<visit.size(); i++) sum+=visit[i];
        return sum;
    }
}
int main() {
    scanf("%d%d%d",&n,&p,&k);
    for (int i=0; i<p; i++) {
        int a, b, l; scanf("%d%d%d",&a,&b,&l);
        G[a-1].push_back((edge){b-1,l});
        G[b-1].push_back((edge){a-1,l});
    }
    printf("%lld\n",dijkstra());
}
