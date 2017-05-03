#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, P> PP;

const ll INF = LLONG_MAX;
int f1 = 1, f2 = 1;

int m, n, k;
vector<PP> p;

bool compx(const P& a, const P& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
bool compy(const P& a, const P& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

struct edge { int to, cost; };

vector<edge> G[200005];
ll d[200005];

void dijkstra() {
    priority_queue<PP, vector<PP>, greator<PP> > que;
    fill(d, d+k+f1+f2, INF);
    d[0] = 0;
    que.push(make_pair(0, P(0, 0)));
    
    while (!que.empty()) {
        PP p = que.top(); que.pop();
        int stat = p.second.second;
        int v = p.second.first;
        if (d[v] < p..first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    scanf("%d%d%d",&m,&n,&k);
    for (int i=0; i<k; i++) {
        int a, b; scanf("%d%d",&a,&b);
        if (a == 1&&b == 1) f1 = 0;
        if (a == m&&b == n) f2 = 0;
        p.push_back(make_pair(i, P(a,b)));
    }
    if (f1) p.push_back(make_pair(k+f1,P(0,0)));
    if (f2) p.push_back(make_pair(k+f1+f2, P(m,n)));
    
    sort(p.begin(), p.end(), compx());
    for (int i=1; i<p.size(); i++) {
        if (p[i].first==p[i-1].first) {
            G[i].push_back((edge){i-1, abs(p[i-1].second-p[i].second)});
            G[i-1].push_back((edge){i, abs(p[i-1].second-p[i].second)});
        }
    }
    sort(p.begin(), p.end(), compy());
    for (int i=1; i<p.size(); i++) {
        if (p[i].second==p[i-1].second) {
            G[i].push_back((edge){i-1, abs(p[i-1].first-p[i].first)});
            G[i-1].push_back((edge){i, abs(p[i].first-p[i].first)});
        }
    }
    dijkstra();
    if (d[p.size()-1]==INF) puts("-1");
    else printf("%lld\n", d[p.size()-1]);
}