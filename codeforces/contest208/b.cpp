#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct unionfind {
    int par[60], rank[60];
    unionfind(int n) {
        for (int i=0; i<n; i++) {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x) {
        if (x==par[x]) return x;
        return par[x]=find(par[x]);
    }
    void unite(int x, int y) {
        x=find(x); y=find(y);
        if (x==y) return;
        if (rank[x]<rank[y]) par[x]=y;
        else {
            par[y]=x;
            if (rank[x]==rank[y]) rank[x]++;
        }
    }
    bool same(int x, int y) {
        return find(x)==find(y);
    }
};
struct edge { int s, e; };
int n;
string card[52];
vector<edge> es;
int d[4]={-1,-3,1,3};
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) cin>>card[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<4; j++) {
            int nx=i+d[j];
            if (nx>=0&&nx<n&&(card[i][0]==card[nx][0]||card[i][1]==card[nx][1])) {
                es.push_back((edge){i,nx});
            }
        }
    }
    unionfind uf(n);
    for (int i=0; i<es.size(); i++) {
        edge e=es[i];
        if (!uf.same(e.s,e.e)) {
            uf.unite(e.s,e.e);
        }
    }
    bool flag=true;
    int r=uf.find(0);
    for (int i=1; i<n; i++) {
        if (r!=uf.find(i)) flag=false;
    }
    if (flag) puts("YES");
    else puts("NO");
}