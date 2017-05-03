// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=jp
// hosさんの資料を参考にする
// lowlinkを計算してそれで判定
// lowlinkの計算のコードでどうしてもメモリエラーが出てしまうので
// http://kagamiz.hatenablog.com/entry/2013/10/05/005213を参考にした
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
vector<int> G[100000];
vector<P> bridge;
vector<int> articulation;
int ord[100000], low[100000];
bool vis[100000];
int v, e, s, t, k;
void dfs(int v, int p, int &k) {
    vis[v] = true;
    ord[v] = k++; low[v] = ord[v];
    bool isArticulation = false;
    int ct = 0;
    for (int i=0; i<G[v].size(); i++) {
        if (!vis[G[v][i]]) {
            ct++;
            dfs(G[v][i], v, k);
            low[v] = min(low[v], low[G[v][i]]);
            if (~p && ord[v] <= low[G[v][i]]) isArticulation = true;
            if (ord[v] < low[G[v][i]]) bridge.push_back(P(min(v, G[v][i]), max(v, G[v][i])));
        } else if (G[v][i] != p) {
            low[v] = min(low[v], ord[G[v][i]]);
        }
    }
    if (p == -1 && ct > 1) isArticulation = true;
    if (isArticulation) articulation.push_back(v);
}
int main() {
    scanf("%d%d",&v,&e);
    for (int i=0; i<e; i++) {
        scanf("%d%d",&s,&t);
        G[s].push_back(t); G[t].push_back(s);
    }
    if (v == 1) {
    } else {
        k = 0;
        for (int i=0; i<v; i++) {
            if (!vis[i]) dfs(i, -1, k);
        }
        sort(articulation.begin(), articulation.end());
        for (int i=0; i<articulation.size(); i++)
            printf("%d\n", articulation[i]);
    }
}
