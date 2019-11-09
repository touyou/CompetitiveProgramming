#include <cstdio>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
struct edge {
int from,to, cost;
bool flag;
};
struct dg { int x, y; };
typedef pair<int, edge*> P;
vector<edge> G[105];
dg dot[105];
bool isdon(int a, int b, int c) {
    long long ax=dot[a].x-dot[b].x, ay=dot[a].y-dot[b].y;
    long long cx=dot[c].x-dot[b].x, cy=dot[c].y-dot[b].y;
    long long ac=ax*cx+ay*cy;
    if (ac<=0) return true;
    else return false;
}
void dijkstra() {
    priority_queue<P, vector<P>, greater<P> > que;
    for (int i=0; i<G[0].size(); i++) {
        que.push(P(G[0][i].cost,&G[0][i]));
    }
    while (!que.empty()) {
        P p=que.top(); que.pop();
        int dist=p.first;
        edge& e=*p.second;
        if (e.flag) continue;
        e.flag=true;
        if (e.to==1) {
            printf("%d\n",dist);
            return;
        }
        for (int i=0; i<G[e.to].size(); i++) {
            edge& e2=G[e.to][i];
            if (isdon(e.from,e.to,e2.to)) {
                que.push(P(dist+e2.cost,&e2));
            }
        }
    }
    puts("-1");
    return;
}
int main() {
    int n, m; scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) scanf("%d%d",&dot[i].x,&dot[i].y);
    for (int i=0; i<m; i++) {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        G[a-1].push_back((edge){a-1,b-1,c,false});
        G[b-1].push_back((edge){b-1,a-1,c,false});
    }
    dijkstra();
}
