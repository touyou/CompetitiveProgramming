#include <cstdio>
#include <iostream>
using namespace std;
#define mod 1000000007
typedef long long ll;
ll dp[2][4]; // 0-D, 1-A, 2-B, 3-C
int main() {
    int n; scanf("%d",&n);
    dp[0][0]=1;
    for (int i=1; i<=n; i++) {
        dp[i&1][0]=(dp[(i-1)&1][1]+dp[(i-1)&1][2]+dp[(i-1)&1][3])%mod;
        dp[i&1][1]=(dp[(i-1)&1][0]+dp[(i-1)&1][2]+dp[(i-1)&1][3])%mod;
        dp[i&1][2]=(dp[(i-1)&1][0]+dp[(i-1)&1][1]+dp[(i-1)&1][3])%mod;
        dp[i&1][3]=(dp[(i-1)&1][0]+dp[(i-1)&1][1]+dp[(i-1)&1][2])%mod;
    }
    cout<<dp[n&1][0]<<endl;
}
