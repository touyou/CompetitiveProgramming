#include <cstdio>
struct unionfind {
    int par[150001], rank[150001];
    unionfind(int n) {
        for (int i=0; i<n; i++) {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x) {
        if (par[x]==x) {
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
};
int n, k;
int main() {
    scanf("%d%d",&n,&k);
    unionfind uf(3*n);
    int res=0;
    for (int i=0; i<k; i++) {
        int t,x,y; scanf("%d%d%d",&t,&x,&y);
        x--; y--;
        if (x<0||n<=x||y<0||n<=y) {
            res++;
            continue;
        }
        if (t==1) {
            if (uf.same(x,y+n)||uf.same(x,y+2*n)) {
                res++;
            } else {
                uf.unite(x,y);
                uf.unite(x+n,y+n);
                uf.unite(x+2*n,y+2*n);
            }
        } else {
            if (uf.same(x,y)||uf.same(x,y+2*n)) {
                res++;
            } else {
                uf.unite(x,y+n);
                uf.unite(x+n,y+2*n);
                uf.unite(x+2*n,y);
            }
        }
    }
    printf("%d\n",res);
}
