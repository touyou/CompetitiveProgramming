#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=80000;
int a[40000];
int dp[40005];
int main() {
    int n; scanf("%d",&n);
    for (int ix=0; ix<n; ix++) {
        int p; scanf("%d",&p);
        fill(dp, dp+40000, INF);
        for (int i=0; i<p; i++) scanf("%d",&a[i]);
        for (int i=0; i<p; i++) {
            *lower_bound(dp, dp+p, a[i])=a[i];
        }
        printf("%d\n",lower_bound(dp,dp+p,INF)-dp);
    }
}
