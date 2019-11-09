#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,cap;
int w[1000], v[1000];
int dp[1005][1000];
int main() {
memset(dp, 0, sizeof(dp));
scanf("%d%d",&n,&cap);
for (int i=0; i<n; i++) scanf("%d%d",&w[i],&v[i]);
for (int i=0; i<n; i++) {
for (int j=cap; j>=0; j--) {
  if (j>=w[i]) dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
  else dp[i+1][j]=dp[i][j];
}}
int res=0;
for (int i=0; i<=cap; i++) res=max(res,dp[n][i]);
printf("%d\n",res);
return 0;
}
