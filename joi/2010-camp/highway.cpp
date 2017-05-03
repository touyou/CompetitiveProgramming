#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define inf INT_MAX/2
typedef pair<int, int> P;
struct edge { int from, to, c1, c2; };
int n, m;
vector<edge*> G[100000];
edge es[100000];
int d[100000];
int dijkstra(int s, int t) {
    fill(d, d+n, inf);
    d[s]=0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0,s));
    while (!que.empty()) {
        P p=que.top(); que.pop();
        int v=p.second;
        if (d[v]<p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e=*G[v][i];
            int cost, to;
            if (v==e.from) {
                cost=e.c1;
                to=e.to;
            } else {
                cost=e.c2;
                to=e.from;
            }
            if (d[to]>d[v]+cost) {
                d[to]=d[v]+cost;
                que.push(P(d[to],to));
            }
        }
    }
    return d[t];
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<n-1; i++) {
        int p, q; scanf("%d%d",&p,&q);
        es[i]=(edge){p-1,q-1,1,1};
        G[p-1].push_back(&es[i]);
        G[q-1].push_back(&es[i]);
    }
    for (int i=0; i<m; i++) {
        char c; cin>>c;
        if (c=='I') {
            int r, s, t; scanf("%d%d%d",&r,&s,&t); r--;
            es[r].c1=s;
            es[r].c2=t;
        } else {
            int x, y; scanf("%d%d",&x,&y);
            printf("%d\n",dijkstra(x-1,y-1));
        }
    }
}
