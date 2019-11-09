#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int k, n;
P node[100000];
map<P, bool> vis;
ll func(ll p) {
  ll ret=1;
  for (ll i=0; i<p; i++) ret*=2;
  return ret;
}
int main() {
  scanf("%d%d",&k,&n);
  for (int i=0; i<n; i++) {
	int p, q; scanf("%d%d",&p,&q);
	node[i]=P(p,q);
	vis[node[i]]=true;
  }
  sort(node, node+n);
  ll ans=func(k+1)-1;
  for (int i=0; i<n; i++) {
	int p=node[i].first, q=node[i].second;
	p--; q=(q+1)/2;
	bool flag=true;
	while (p>=0) {
	  if (vis[P(p,q)]) {
		flag=false;
		break;
	  }
	  p--;
	  q=(q+1)/2;
	}
	if (!flag) continue;
	ans-=func(k-node[i].first+1)-1;
  }
  printf("%lld\n",ans);
}
