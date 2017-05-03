#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long ll;
struct c { ll c, t, s; };
class Comp {
	public:
		bool operator() (const c& a, const c& b) {
			return a.s > b.s;
		}
};	
ll solve(int n, int k, c coff[]) {
	// int res = 0;
	// sort(coff, coff+n, Comp());
	// for (int i=0; i<n; i++) {
		// for (int j=i+1; j<n; j++) {
			// if (coff[i].t==coff[j].t&&coff[i].s>coff[j].s) {
				// swap(coff[i], coff[j]);
			// }
		// }
	// }
	// int days[k+1];
	// for (int i=0; i<=k; i++) days[i] = 0;
	// for (int i=n-1; i>=0; i--) {
		// for (int j=coff[i].t; j>0&&coff[i].c>0; j--) {
			// if (days[j] < coff[i].s) {
				// days[j] = coff[i].s;
				// coff[i].c--;
			// }
		// }
	// }
	// for (int i=1; i<=k; i++) res += days[i];
	// return res;
	ll res = 0;
	sort(coff,coff+n,Comp());
	for (int i=0; i<n; i++) {
		int val = coff[i].s;
		if (coff[i].t==0) continue;
		ll begin=max(1LL, coff[i].t-coff[i].c+1);
		ll end=coff[i].t;
		res+=(end-begin+1)*val;
		for (int j=0; j<n; j++) {
			if (coff[j].t>end) {
				coff[j].t-=end-begin+1;
			} else {
				coff[j].t=min(coff[j].t,begin-1);
			}
		}
	}
	return res;
}
int main() {
	int t; scanf("%d", &t);
	for (int ix=1; ix<=t; ix++) {
		int n, k; scanf("%d%d",&n,&k);
		c coff[n];
		for (int i=0; i<n; i++) {
			scanf("%lld%lld%lld",&coff[i].c,&coff[i].t,&coff[i].s);
		}
		printf("Case #%d: %lld\n", ix, solve(n,k,coff));
	}
}