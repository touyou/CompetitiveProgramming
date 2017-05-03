#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
ll dp[128][128];
int main() {
  dp[0][0] = 1;
  for (int i=1; i<128; i++) {
	for (int j=0; j<128; j++) {
	  if (j) dp[i][j] += dp[i-1][j-1];
	  dp[i][j] += dp[i-1][j];
	}
  }
  while (scanf("%d%d",&n,&m)) {
	if (!n&&!m) break;
	printf("%d things taken %d at a time is %lld exactly.\n",n,m,dp[n][m]);
  }
}
