#include "grader.h"
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct unionfind {
    int par[100000], rank[100000];
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
        x=find(x); y=find(y);
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
struct edge {
    int from, to;
    ll cost;
};
bool comp(const edge& a, const edge& b) {
    return a.cost<b.cost;
}
vector<edge> es;
void construct(int N, int M, int E[][3]) {
  for(int i = 2; i <= N; i++) {
    es.clear();
    for (int j=0; j<M; j++) {
        if (E[j][1]<i) {
            es.push_back((edge){E[j][0],E[j][1],E[j][2]});
        }
    }
    unionfind uf(i+1);
    sort(es.begin(), es.end(), comp);
    ll res=0;
    for (int j=0; j<es.size(); j++) {
        edge e=es[j];
        if (!uf.same(e.from,e.to)) {
            uf.unite(e.from, e.to);
            res+=e.cost;
        }
    }
    for (int j=1; j<i; j++) {
        if (!uf.same(0,j)) res=-1;
    }
    answer(res);
  }
}

