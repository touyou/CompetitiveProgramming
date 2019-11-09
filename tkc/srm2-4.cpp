#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
	int n, d;
	scanf("%d%d",&n,&d);
	int m[n], i;
	for (i=0; i<n; i++) scanf("%d", &m[i]);
	int res=INT_MIN;
	sort(m,m+n);
	for (i=0; i<n; i++) {
		int x = m[i]+d*2;
		res=max(upper_bound(m, m+n, x)-m-i, res);
	}
	printf("%d\n",res);
}
