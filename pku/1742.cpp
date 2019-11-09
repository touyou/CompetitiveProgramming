#include <cstdio>
#include <cstring>
int dp[100001];
int a[100], c[100];
int main() {
    int n, m;
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m) break;
        for (int i=0; i<n; i++) scanf("%d",&a[i]);
        for (int i=0; i<n; i++) scanf("%d",&c[i]);
        memset(dp, -1, sizeof(dp));
        dp[0]=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=m; j++) {
                if (dp[j]>=0) {
                    dp[j]=c[i];
                } else if (j<a[i]||dp[j-a[i]]<=0) {
                    dp[j]=-1;
                } else {
                    dp[j]=dp[j-a[i]]-1;
                }
            }
        }
        int res=0;
        for (int i=1; i<=m; i++) if (dp[i]!=-1) res++;
        printf("%d\n",res);
    }
}
