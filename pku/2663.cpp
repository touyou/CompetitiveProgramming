#include <cstdio>
typedef long long ll;
int main() {
    ll dp[31];
    dp[2]=3;
    dp[4]=11;
    for (int i=1; i<31; i+=2) dp[i]=0;
    for (int i=6; i<31; i+=2) {
        dp[i]=2;
        for (int j=i-2; j>i/2; j--) dp[i]+=dp[j]*dp[i-j]*2-dp[i-j]*dp[i-j]*dp[2*j-i];
        if (i%4==0) dp[i]+=4;
    }
    int n;
    while (scanf("%d",&n)) {
        if (n==-1) break;
        printf("%lld\n",dp[n]);
    }
}
