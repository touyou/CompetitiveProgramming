#include <cstdio>
#include <cstring>

// bit dp -> 一行ごとの情報

int d, n, m, k;
int xy[150][10];
int dp[2][1<<10];

int main() {
  scanf("%d",&d);
  for (int ix=0; ix<d; ix++) {
    scanf("%d%d%d",&n,&m,&k);
    memset(xy, 0, sizeof(xy));
    for (int i=0; i<k; i++) {
      int x, y; scanf("%d%d",&x,&y);
      xy[x-1][y-1]=1;
    }
    memset(dp, 0, sizeof(dp));
    int *crt=dp[0], *next=dp[1];
    crt[0] = 1;
    for (int i=n-1; i>=0; i--) {
      for (int j=m-1; j>=0; j--) {
        for (int used=0; used < 1<<m; used++) {
          if ((used>>j&1) || xy[i][j]) {
            next[used] = crt[used & ~(1<<j)];
          } else {
            int res = 0;
            if (
        }
      }
    }
  }
  return 0;
}
