#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	int dp[n];
	fill(dp,dp+n,INT_MAX);
	for (int i=0; i<n; i++)
		*lower_bound(dp,dp+n,a[i])=a[i];
	printf("%d\n",lower_bound(dp,dp+n,INT_MAX)-dp);
}