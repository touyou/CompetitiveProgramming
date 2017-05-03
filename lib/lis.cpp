#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
int dp[N];
int N;
int a[N];
void solve() {
	fill(dp,dp+N,INT_MAX);
	for (int i=0; i<N; i++) {
		*lower_bound(dp,dp+N,a[i]) = a[i];
	}
	printf("%d\n",lower_bound(dp,dp+N,INT_MAX)-dp);
}
