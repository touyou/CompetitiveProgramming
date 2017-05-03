#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
struct unionfind {
    int par[10000], rank[10000];
    unionfind(int n) {
        for (int i=0; i<n; i++) {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x) {
        if (x==par[x]) {
            return x;
        } else {
            return par[x]=find(par[x]);
        }
    }
    void unite(int x, int y) {
        x=find(x);
        y=find(y);
        if (x==y) return;
        if (rank[x]<rank[y]) {
            par[x]=y;
        } else {
            par[y]=x;
            if (rank[x]==rank[y]) rank[x]++;
        }
    }
    bool same(int x, int y) {
        return find(x)==find(y);
    }
    int cnt(int n) {
        set<int> pars;
        for (int i=0; i<n; i++) {
            int x=find(i);
            pars.insert(x);
        }
        return pars.size();
    }
};
int main() {
    int n, m; scanf("%d%d",&n,&m);
    unionfind uf(n);
    for (int i=0; i<m; i++) {
        int a, b; scanf("%d%d",&a,&b);
        uf.unite(a-1,b-1);
    }
    printf("%d\n",uf.cnt(n)-1);
}
