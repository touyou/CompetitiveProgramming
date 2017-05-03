#include <cstdio>
#include <iostream>
using namespace std;
struct unionfind {
    int par[6000], rank[6000];
    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x) {
        if (par[x]==x) return x;
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
int t, b, s;
unionfind uf;
int main() {
    scanf("%d",&t);
    for (int ix=1; ix<=t; ix++) {
        scanf("%d%d",&b,&s);
        uf.init(b*2);
        bool flag=true;
        for (int i=0; i<s; i++) {
            int a1, a2; scanf("%d%d",&a1,&a2); a1--; a2--;
            if (uf.same(a1,a2)||uf.same(a1+b,a2+b)) flag=false;
            uf.unite(a1,a2+b); uf.unite(a1+b,a2);
        }
        printf("Scenario #%d:\n",ix);
        if (flag) puts("No suspicious bugs found!");
        else puts("Suspicious bugs found!");
        puts("");
    }
}