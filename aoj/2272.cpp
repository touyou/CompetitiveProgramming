#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#define inf INT_MAX/2
using namespace std;
typedef pair<int, int> P;
struct edge { int to, cost; };
int h, w;
vector<edge> G[2500];
int d[2500];
string field[50];
int dijkstra() {
    fill(d, d+2500, inf);
    d[0]=0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0,0));
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
    return d[h*w-1];
}
int main() {
    scanf("%d%d",&h,&w);
    for (int i=0; i<h; i++) {
            cin>>field[i];
    }
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (i!=h-1) {
                G[i*w+j].push_back((edge){(i+1)*w+j,field[i+1][j]-'0'});
            }
            if (j!=w-1) {
                G[i*w+j].push_back((edge){i*w+j+1,field[i][j+1]-'0'});
            }
        }
    }
    printf("%d\n",dijkstra());
}
