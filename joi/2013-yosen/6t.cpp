#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <functional>
#define x first
#define y second
#define INF INT_MAX/2
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
struct edge {
    int to, cost;
    edge() {}
    edge(int to, int cost) : to(to), cost(cost) {}
};
int h, w, k, V;
string f[50];
vector<P> shop;
vector<edge> G[2500];
int vis[50][50];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,-1};

int bfs(int from, int to) {
    int cost=INF;
    queue<pair<P, int> > que;
    que.push(make_pair(shop[from], 0));
    memset(vis, 0, sizeof(vis));
    while (!que.empty()) {
        P p = que.front().first;
        int cnt=que.front().second;
        if (p.x==shop[to].x&&p.y==shop[to].y) {
            cost=min(cost, cnt);
            continue;
        }
        vis[p.x][p.y]=1;
        for (int i=0; i<4; i++) {
            int nx=p.x+dx[i], ny=p.y+dy[i];
            if (nx<0||nx>=h||ny<0||ny>=w) continue;
            if (vis[nx][ny]||f[nx][ny]=='#') continue;
            if (i<2) que.push(make_pair(P(nx,ny),cnt+1));
            else que.push(make_pair(P(nx,ny),cnt));
        }
    }
    return cost;
}

int dij() {
    V=shop.size()-1;
    queue<pair<int, P> > que;
    que.push(make_pair(0,P(0,0)));
    int res=0;
    while (!que.empty()) {
        int cnt=que.front().x;
        int amt=que.front().y.x;
        int pos=que.front().y.y;
        if (pos==V) {
            res=max(amt,res);
        }
        for (int i=0; i<G[pos].size(); i++) {
            if (cnt+G[pos].cost>=k) continue;
            que.push(make_pair(cnt+G[pos].cost,P(amt+

int main() {
    scanf("%d%d%d",&h,&w,&k);
    for (int i=0; i<h; i++) cin>>f[i];
    shop.push_back(P(0,0));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (f[i][j]!='#'&&f[i][j]!='.') shop.push_back(P(i,j));
        }
    }
    shop.push_back(P(h-1,w-1));
    for (int i=0; i<shop.size(); i++) {
        for (int j=i+1; j<shop.size(); j++) {
            G[i].push_back(edge(j,bfs(i,j)));
        }
    }
    printf("%d\n",dij());
}
