#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
#define max_v 1000000
#define inf INT_MAX/2
struct edge { int to, cap, rev; };
vector<edge> G[max_v];
bool used[max_v];
// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){to,0,G[from].size()-1});
}
// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
    if (v==t) return f;
    used[v]=true;
    for (int i=0; i<G[v].size(); i++) {
        edge &e=G[v][i];
        if (!used[e.to]&&e.cap>0) {
            int d=dfs(e.to,t,min(f,e.cap));
            if (d>0) {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
// sからtまでの最大流
int max_flow(int s, int t) {
    int flow=0;
    for (;;) {
        memset(used,0,sizeof(used)); // 0=false
        int f=dfs(s,t,inf);
        if (f==0) return flow;
        flow+=f;
    }
}
