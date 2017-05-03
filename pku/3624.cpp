#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,w[3402],v[3402];
int dp[12881];
int main() {
    scanf("%d%d",&n,&m);
    int ans=0;
    for (int i=0; i<n; i++) scanf("%d%d",&w[i],&v[i]);
    for (int i=0; i<m; i++) dp[i]=0;
    for (int i=0; i<n; i++) {
        for (int j=m; j>=w[i]; j--) {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            ans=max(ans,dp[j]);
        }
    }
    printf("%d\n",ans);
}
