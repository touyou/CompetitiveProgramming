#include <cstdio>
#include <cstring>
typedef long long ll;
int x, y;
ll dp[20][20];
int mp[20][20];
int main() {
  while (scanf("%d%d",&x,&y)) {
    if (!x&&!y) break;
    memset(dp, 0, sizeof(dp));
    memset(mp, 0, sizeof(mp));
    for (int i=0; i<y; i++) {
      for (int j=0; j<x; j++) scanf("%d",&mp[i][j]);
    }
    for (int i=0; i<x; i++) if (mp[0][i]!=1) dp[0][i]=1;
    ll res = 0;
    for (int i=0; i<y-1; i++) {
      for (int j=0; j<x; j++) {
        if (mp[i][j]==2&&mp[i+2][j]!=1) {
          dp[i+2][j]+=dp[i][j];
        } else if (mp[i][j]==0) {
          if (j-1>=0&&mp[i+1][j-1]==0) dp[i+1][j-1]+=dp[i][j];
          if (mp[i+1][j]!=1) dp[i+1][j]+=dp[i][j];
          if (j+1<x&&mp[i+1][j+1]==0) dp[i+1][j+1]+=dp[i][j];
        }
      }
    }
    for (int i=0; i<x; i++) res+=dp[y][i]+dp[y-1][i];
    printf("%lld\n",res);
  }
}
