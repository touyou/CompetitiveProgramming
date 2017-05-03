#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf LLONG_MAX/2
ll g[100000];
ll dp[100001];
int main() {
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        int n; scanf("%d",&n);
        for (int i=0; i<n; i++) scanf("%lld",&g[i]);
        fill(dp, dp+n, inf);
        ll res=0;
        for (int i=0; i<n; i++) {
            ll &a=*lower_bound(dp,dp+n,g[i]);
            ll &b=*(lower_bound(dp,dp+n,g[i])+1);
            if (b==inf) res=max(res,g[i]-dp[0]);
            a=g[i];
        }
        if (res>0) printf("%lld\n",res);
        else puts("UNFIT");
    }
}
