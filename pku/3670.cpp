#include <cstdio>
#include <algorithm>
using namespace std;
int dp[30000][3];
int card[30000];
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&card[i]);
    int ans=n;
    for (int k=0; k<2; k++) {
        for (int j=0; j<3; j++) dp[0][j]=(card[0]!=j+1);
        for (int i=1; i<n; i++) {
            dp[i][0]=dp[i-1][0]+(card[i]!=1);
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+(card[i]!=2);
            dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+(card[i]!=3);
        }
        reverse(card, card+n);
        for (int i=0; i<3; i++) ans=min(ans,dp[n-1][i]);
    }
    printf("%d\n",ans);
}
