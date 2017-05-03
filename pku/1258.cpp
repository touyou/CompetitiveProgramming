#include <cstdio>
#include <algorithm>
#define INF 1000001
using namespace std;
typedef long long ll;
int cost[100][100];
int mincost[100];
bool used[100];
int V;
ll prim() {
    for (int i=0; i<V; i++) {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    ll res=0;
    while (true) {
        int v = -1;
        for (int u=0; u<V; u++) {
            if (!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        }
        if (v==-1) break;
        used[v]=true;
        res+=mincost[v];
        for (int u=0; u<V; u++) {
            mincost[u]=min(mincost[u], cost[v][u]);
        }
    }
    return res;
}
int main() {
    while (scanf("%d",&V)!=EOF) {
        for (int i=0; i<V; i++) for (int j=0; j<V; j++) {
            scanf("%d",&cost[i][j]);
            if (i==j) cost[i][j]=INF;
        }
        printf("%lld\n",prim());
    }
}
