#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll p[65000], j[65000];
int main() {
  while (scanf("%d",&n)) {
	if (!n) break;
	ll sum=0;
	for (int i=0; i<n; i++) {
	  scanf("%lld",&p[i]);
	  sum+=p[i];
	}
	for (int i=0; i<n-1; i++) scanf("%lld",&j[i]);
	sort(j, j+n-1);
	ll res=sum*n;
	for (int i=n-2; i>=0; i--) {
	  sum+=j[i];
	  res=max(res, sum*(i+1));
	}
	printf("%lld\n",res);
  }
}
