#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
int t, n, m;
P a[100], b[100];
ll dp[101][101];
ll dfs(int i, int j) {
    if (i>=n||j>=m) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    ll res=0;
    if (a[i].second!=b[j].second) res=max(dfs(i,j+1),dfs(i+1,j));
    else {
        ll useA=0, useB=0;
        int x=a[i].second;
        for (int k=i; k<n; k++) {
            if (a[k].second!=x) continue;
            useA+=a[k].first;
            useB=0;
            for (int l=j; l<m; l++) {
                if (b[l].second!=x) continue;
                useB+=b[l].first;
                res=max(res,dfs(k+1,l+1)+min(useA,useB));
            }
        }
    }
    return dp[i][j]=res;
}
int main() {
    scanf("%d",&t);
    for (int ix=1; ix<=t; ix++) {
        scanf("%d%d",&n,&m);
        memset(dp,-1,sizeof(dp));
        for (int i=0; i<n; i++) {
            scanf("%lld%d",&a[i].first,&a[i].second);
        }
        for (int i=0; i<m; i++) {
            scanf("%lld%d",&b[i].first,&b[i].second);
        }
        printf("Case #%d: %lld\n",ix,dfs(0,0));
    }
}
