#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int n, dp[2][5050][2],t[10000];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        scanf("%d",&t[i]);
    }
    for (int i=0; i<2; i++) for (int j=0; j<5050; j++) for (int k=0; k<2; k++) dp[i][j][k]=INT_MAX/2;
    dp[0][0][0]=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=min(5009,i); j++) {
            dp[(i+1)&1][j+1][0]=min(dp[i&1][j][0], dp[i&1][j][1]+t[i]);
            dp[(i+1)&1][j][1]=min(dp[i&1][j][0]+t[i], dp[i&1][j][1]);
        }
        dp[i&1][0][0]=INT_MAX/2;
    }
    printf("%d\n",dp[n%2][n/2][0]);
}