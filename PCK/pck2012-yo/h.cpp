#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, c;
int a[30], b[30];
int dp[2][1<<16];
int main() {
  while (scanf("%d%d",&n,&c)) {
	if (!n&&!c) break;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; i++) {
	  for (int j=0; j<16; j++) {
		int in; scanf("%d",&in);
		if (in) a[i] |= (1<<j);
	  }
	}
	for (int i=0; i<c; i++) {
	  for (int j=0; j<16; j++) {
		int in; scanf("%d",&in);
		if (in) b[i] |= (1<<j);
	  }
	}
	dp[0][0]=0;
	for (int i=0; i<n; i++) {
	  memset(dp[(i+1)&1], -1, sizeof(dp[i&1]));
	  for (int S=0; S<(1<<16); S++) {
		if (dp[i&1][S]==-1) continue;
		dp[(i+1)&1][S|a[i]]=max(dp[(i+1)&1][S|a[i]], dp[i&1][S]);
		for (int j=0; j<c; j++) {
		  dp[(i+1)&1][(S|a[i])&(~b[j])]=max(dp[(i+1)&1][(S|a[i])&(~b[j])], dp[i&1][S]+__builtin_popcount((S|a[i])&b[j]));
		  printf("%d\n",__builtin_popcount((S|a[i])&b[j]));
		}
	  }
	}
	int res=0;
	for (int S=0; S<(1<<16); S++) {
	  res=max(res, dp[n&1][S]);
	}
	printf("%d\n",res);
  }
}
