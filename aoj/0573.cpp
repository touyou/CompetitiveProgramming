#include <cstdio>
#include <algorithm>
using namespace std;
int a[3000], b[3000];
int dp[5000];
int main() {
    int n, t, s; scanf("%d%d%d",&n,&t,&s);
    for (int i=0; i<n; i++) scanf("%d%d",&a[i],&b[i]);
    int res=0;
    for (int i=0; i<n; i++) {
        for (int j=t-b[i]; j>=0; j--) {
            if (j<s&&s<j+b[i]) continue;
            dp[j+b[i]]=max(dp[j+b[i]], dp[j]+a[i]);
            res=max(res,dp[j+b[i]]);
        }
    }
    printf("%d\n",res);
}
