#include <cstdio>
#include <cstring>
#define mod 100000
int n, m, s;
int dp[3001][50];
int main() {
    while (scanf("%d%d%d",&n,&m,&s)) {
        if (!n&&!m&&!s) break;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for (int i=1; i<=m; i++) {
            for (int j=n*n; j>0; j--) {
                for (int k=s; k>=i; k--) {
                    dp[k][j]=(dp[k][j]+dp[k-i][j-1])%mod;
                }
            }
        }
        printf("%d\n",dp[s][n*n]);
    }
}
