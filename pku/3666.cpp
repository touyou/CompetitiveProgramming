#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int a[2000];
int dp[2000];
ll solve() {
    dp[0]=a[0];
    ll res=0;
    for (int i=1; i<n; i++) {
        if (dp[i-1]>a[i]) dp[i]=dp[i-1];
        else dp[i]=a[i];
        res+=abs(dp[i]-a[i]);
    }
    return res;
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    ll res=solve();
    reverse(a, a+n);
    printf("%lld\n",min(res,solve()));
}
