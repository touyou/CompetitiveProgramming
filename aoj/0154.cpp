#include <cstdio>
#include <cstring>
typedef long long ll;
int m, g;
int a[7], b[7];
ll dp[8][1001];
int main() {
    while (scanf("%d",&m)) {
        if (!m) break;
        for (int i=0; i<m; i++) scanf("%d%d",&a[i],&b[i]);
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;
        for (int i=0; i<m; i++) {
            for (int k=0; k<=1000; k++) {
                for (int j=0; j<=b[i]; j++) {
                    if (k+a[i]*j>1000) continue;
                    dp[i+1][k+a[i]*j]+=dp[i][k];
                }
            }
        }
        scanf("%d",&g);
        for (int i=0; i<g; i++) {
            int n; scanf("%d",&n);
            printf("%lld\n",dp[m][n]);
        }
    }
}
