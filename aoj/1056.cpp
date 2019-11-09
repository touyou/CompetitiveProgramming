#include <cstdio>
#include <cstring>
int n;
double dp[100000][2];
int main() {
    memset(dp, 0, sizeof(dp));
    dp[0][1]=1.0;
    for (int i=1; i<100000; i++) {
        dp[i][1]=dp[i-1][1]*0.5+dp[i-1][0];
        dp[i][0]=dp[i-1][1]*0.5;
    }
    while (scanf("%d",&n)) {
        if (!n) break;
        double res=0.0;
        for (int i=0; i<n; i++) {
            res+=dp[i][1];
        }
        printf("%f\n",res);
    }
}
