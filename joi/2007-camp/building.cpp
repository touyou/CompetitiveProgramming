#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 20000
int main() {
	int n; scanf("%d",&n);
	int a[n], dp[n];
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	fill(dp, dp+n, INF);
	for (int i=0; i<n; i++) {
		*lower_bound(dp,dp+n,a[i])=a[i];
	}
	printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
}
