#include <cstdio>
#include <algorithm>
using namespace std;
#define mod 10000
int day[100];
long long dp[100][3][3];
int main() {
    int n, k; scanf("%d%d",&n,&k);
    for (int i=0; i<k; i++) {
        int a,b; scanf("%d%d",&a,&b);
        day[a-1]=b;
    }
    if (day[0]) {
        dp[0][day[0]-1][0]=dp[0][day[0]-1][2]=1;
    } else {
        dp[0][0][0]=dp[0][1][0]=dp[0][2][0]=1;
        dp[0][0][2]=dp[0][1][2]=dp[0][2][2]=1;
    }
    for (int i=1; i<n; i++) {
        if (day[i]==1) {
            dp[i][0][0]=(dp[i-1][1][2]+dp[i-1][2][2])%mod;
            dp[i][0][1]=dp[i-1][0][0];
            dp[i][0][2]=(dp[i][0][1]+dp[i][0][0])%mod;
        } else if (day[i]==2) {
            dp[i][1][0]=(dp[i-1][0][2]+dp[i-1][2][2])%mod;
            dp[i][1][1]=dp[i-1][1][0];
            dp[i][1][2]=(dp[i][1][1]+dp[i][1][0])%mod;
        } else if (day[i]==3) {
            dp[i][2][0]=(dp[i-1][0][2]+dp[i-1][1][2])%mod;
            dp[i][2][1]=dp[i-1][2][0];
            dp[i][2][2]=(dp[i][2][1]+dp[i][2][0])%mod;
        } else {
            dp[i][0][0]=(dp[i-1][1][2]+dp[i-1][2][2])%mod;
            dp[i][0][1]=dp[i-1][0][0];
            dp[i][0][2]=(dp[i][0][1]+dp[i][0][0])%mod;
            dp[i][1][0]=(dp[i-1][0][2]+dp[i-1][2][2])%mod;
            dp[i][1][1]=dp[i-1][1][0];
            dp[i][1][2]=(dp[i][1][1]+dp[i][1][0])%mod;
            dp[i][2][0]=(dp[i-1][0][2]+dp[i-1][1][2])%mod;
            dp[i][2][1]=dp[i-1][2][0];
            dp[i][2][2]=(dp[i][2][1]+dp[i][2][0])%mod;
        }
    }
    printf("%lld\n",(dp[n-1][0][2]+dp[n-1][1][2]+dp[n-1][2][2])%mod);
}
