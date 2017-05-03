#include <cstdio>
#define MOD 100000
typedef long long ll;
ll dp[100][100][2][2];  // i,j,k,l---(i,j)＝今いる地点、k＝左から０下から１、l=直前で曲がったか?1:0
int main() {
    for (int i=0; i<100; i++) {
        dp[0][i][0][0]=dp[i][0][1][0]=1;
    }
    for (int i=1; i<100; i++) {
        for (int j=1; j<100; j++) {
            dp[i][j][0][0]=(dp[i][j-1][0][0]+dp[i][j-1][0][1])%MOD;
            dp[i][j][0][1]=dp[i][j-1][1][0]%MOD;
            dp[i][j][1][0]=(dp[i-1][j][1][0]+dp[i-1][j][1][1])%MOD;
            dp[i][j][1][1]=dp[i-1][j][0][0]%MOD;
        }
    }
    int w, h;
    while (scanf("%d%d",&w,&h)) {
        if (!w&&!h) break;
        ll res=(dp[h-1][w-1][0][0]+dp[h-1][w-1][0][1]+dp[h-1][w-1][1][0]+dp[h-1][w-1][1][1])%MOD;
        printf("%lld\n",res);
    }
}
