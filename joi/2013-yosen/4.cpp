#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int d, n, t[200], a[200], b[200], c[200];
int dp[200][200], cx[200][200];
int main() {
    scanf("%d%d",&d,&n);
    for (int i=0; i<d; i++) scanf("%d",&t[i]);
    for (int i=0; i<n; i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        cx[i][j]=abs(c[i]-c[j]);
    }
    for (int i=0; i<n; i++) {
        if (t[0]<a[i]||b[i]<t[0]) dp[0][i]=-1;
    }
    for (int i=1; i<d; i++) {
        for (int j=0; j<n; j++) {
            if (t[i]<a[j]||b[j]<t[i]) {
                dp[i][j]=-1; continue;
            }
            for (int k=0; k<n; k++) {
                if (dp[i-1][k]==-1) continue;
                dp[i][j]=max(dp[i][j],dp[i-1][k]+cx[j][k]);
            }
        }
    }
    int res=0;
    for (int i=0; i<n; i++) res=max(res, dp[d-1][i]);
    printf("%d\n",res);
}
