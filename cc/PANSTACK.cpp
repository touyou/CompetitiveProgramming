#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll dp[1000][1005];
int main() {
    int t; scanf("%d",&t);
    memset(dp, 0, sizeof(dp));
    dp[0][1]=1;
    for (int i=1; i<1000; i++) {
        for (int j=1; j<=1000; j++) {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%mod;
        }
    }
    for (int ix=0; ix<t; ix++) {
        int n; scanf("%d",&n);
        ll res=0;
        for (int i=1; i<=1000; i++) res=(res+dp[n-1][i])%mod;
        printf("%lld\n",res);
    }
}
