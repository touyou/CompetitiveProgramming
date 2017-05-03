#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#define inf LLONG_MAX/2
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct edge { int to, cost; };

int n, m, k, q;
vector<edge> G[100000];
ll d[100000], mind[100000];
int vs[200000], depth[200000], id[100000];

// dijkstra
void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+n, inf);
    d[s]=0;
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
    for (int i=0; i<n; i++) {
        mind[i]=min(mind[i], d[i]);
    }
}
// 最小全域木

// lcm


int main() {
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for (int i=0; i<m; i++) {
        int a, b, l; scanf("%d%d%d",&a,&b,&l);
        G[a-1].push_back((edge){b-1,l});
        G[b-1].push_back((edge){a-1,l});
    }
    fill(mind, mind+n, inf);
    for (int i=0; i<k; i++) {
        int f; scanf("%d",&f);
        dijkstra(f-1);
    }
    init(n);
    for (int i=0; i<q; i++) {
        int s, t; scanf("%d%d",&s,&t);
        s--; t--;
    }
}
