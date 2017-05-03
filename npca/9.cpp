#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int a[100], b[100];
int dp[2][100001];
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) scanf("%d%d",&a[i],&b[i]);
    for (int i=0; i<m; i++) {
        for (int j=0; j<=n; j++) {
            if (j<a[i]) dp[i&1][j]=dp[(i-1)&1][j];
            else {
                dp[i&1][j]=max(dp[(i-1)&1][j], dp[(i-1)&1][j-a[i]]+b[i]);
            }
        }
    }
    int res=0;
    for (int i=0; i<=n; i++) res=max(res, dp[(m-1)&1][i]);
    printf("%d\n",res);
}
