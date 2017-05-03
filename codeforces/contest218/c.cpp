#include <cstdio>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> P;
struct uf {
  int par[10000], rank[10000];
  uf(int n) {
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
  bool same(int x, int y) { return find(x)==find(y); }
};
int n;
P xy[1000];
int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) scanf("%d%d",&xy[i].first,&xy[i].second);
  uf u(n);
  for (int i=0; i<n; i++) {
	for (int j=i+1; j<n; j++) {
	  if (xy[i].first==xy[j].first||xy[i].second==xy[j].second) u.unite(i,j);
	}
  }
  set<int> ret;
  for (int i=0; i<n; i++) ret.insert(u.find(i));
  printf("%d\n",ret.size()-1);
}
