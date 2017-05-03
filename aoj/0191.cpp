#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m) break;
        double grow[n][n], dp[m][n];
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%lf",&grow[i][j]);
        for (int i=0; i<n; i++) dp[0][i]=1.0;
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                dp[i][j]=0.0;
                for (int k=0; k<n; k++) dp[i][j]=max(dp[i][j], dp[i-1][k]*grow[k][j]);
            }
        }
        double res=0.0;
        for (int i=0; i<n; i++) res=max(res, dp[m-1][i]);
        printf("%.2lf\n",res);
    }
}
