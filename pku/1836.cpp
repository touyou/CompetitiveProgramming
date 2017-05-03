#include <cstdio>
#include <algorithm>
using namespace std;
const double INF=100.0;
double a[1000];
double dp[1001];
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%lf",&a[i]);
    fill(dp, dp+n+1, INF);
    for (int i=0; i<n; i++) {
        *upper_bound(dp, dp+n+1, a[i])=a[i];
    }
    int res=n-(lower_bound(dp,dp+n+1,INF)-dp);
    fill(dp, dp+n+1, INF);
    reverse(a, a+n);
    for (int i=0; i<n; i++) {
        *upper_bound(dp, dp+n+1, a[i])=a[i];
    }
    printf("%d\n",min(res,n-(lower_bound(dp,dp+n+1,INF)-dp)));
}
