#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define max_v 1000000
#define inf INT_MAX/2
struct edge { int to, cap, rev; };
vector<edge> G[max_v];
int level[max_v];   // sからの距離
int iter[max_v];    // どこまで調べ終わったか
// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){to,0,G[from].size()-1});
}
// sからの最短距離をBFSで計算する
void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while (!que.empty()) {
        int v=que.front(); que.pop();
        for (int i=0; i<G[v].size(); i++) {
            edge &e=G[v][i];
            if (e.cap>0&&level[e.to]<0) {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
    if (v==t) return f;
    for (int &i=iter[v]; i<G[v].size(); i++) {
        edge &e=G[v][i];
        if (e.cap>0&&level[v]<level[e.to]) {
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
        bfs(s);
        if (level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while ((f=dfs(s,t,inf))>0) {
            flow+=f;
        }
    }
}
