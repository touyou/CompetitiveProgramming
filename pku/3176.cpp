#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n; scanf("%d",&n);
	int map[n][n];
	for (int i=0; i<n; i++) for (int j=0; j<i+1; j++) scanf("%d",&map[i][j]);
	int dp[n][n];
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) dp[i][j]=0;
	dp[0][0]=map[0][0];
	for (int i=1; i<n; i++) {
		dp[i][0]=map[i][0]+dp[i-1][0];
		dp[i][i]=map[i][i]+dp[i-1][i-1];
		for (int j=1; j<i; j++) {
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+map[i][j];
		}
	}
	int res=0;
	for (int i=0; i<n; i++) res=max(res,dp[n-1][i]);
	printf("%d\n",res);
}