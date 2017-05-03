#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, pic[100];
bool dp[111][55001];
int main() {
    scanf("%d",&n);
    int sum=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&pic[i]);
        sum+=pic[i];
    }
    dp[0][0]=true;
    for (int i=0; i<n; i++) {
        for (int u=n-1; u>=0; u--) {
            for (int j=0; j<=sum; j++) if (dp[u][j]) dp[u+1][j+pic[i]]=true;
        }
    }
    int r1=0, r2=sum;
    for (int i=0; i<sum; i++) {
        if (!dp[n/2][i]) continue;
        if (abs(r2-r1)>abs(sum-2*i)) {
            r1=i;
            r2=sum-i;
        }
    }
    if (r1>r2) swap(r1,r2);
    printf("%d %d\n",r1,r2);
}