#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n, l;
    scanf("%d%d",&n,&l);
    int ice[n],dp[n];
    pair<int, int> row[n];
    for (int i=0; i<n; i++) {
        scanf("%d",&ice[i]);
        row[i].first=ice[i];
        row[i].second=i;
    }
    sort(row, row+n);
    int res=0;
    for (int i=n-1; i>=0; i--) {
        int k=row[i].second, k1=row[i].second-1, k2=row[i].second+1;
        dp[k]=0;
        if (k1>=0&&ice[k1]==0) dp[k]=dp[k1];
        if (k2<n&&ice[k2]==0) dp[k]=max(dp[k], dp[k2]);
        dp[k]+=l-ice[k];
        ice[k]=0;
        res=max(res,dp[k]);
    }
    printf("%d\n",res);
}
