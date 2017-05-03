#include <cstdio>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;
ll d[10], v[10];
ll gcd(ll a, ll b) {
  return a%b==0?b:gcd(b,a%b);
}
ll lcm(ll a, ll b) {
  return a*b/gcd(a,b);
}
int main() {
  while (scanf("%d",&n)) {
	if (n==0) break;
	set<P> s;
	for (int i=0; i<n; i++) {
	  scanf("%lld%lld",&d[i],&v[i]);
	  ll gc=gcd(d[i], v[i]);
	  d[i]/=gc; v[i]/=gc;
	  s.insert(P(d[i],v[i]));
	}
	if (s.size()==1) {
	  for (int i=0; i<n; i++) puts("1");
	} else {
	  
	}
  }
}
