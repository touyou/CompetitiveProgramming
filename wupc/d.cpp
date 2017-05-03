#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, dp[100][100], a[100][100];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) for (int j=0; j<=i; j++) scanf("%d",&a[i][j]);
    memset(dp, 0, sizeof(dp));
    dp[0][0]=a[0][0];
    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            int x=0, y=dp[i-1][j];
            if (j!=0) x=dp[i-1][j-1];
            dp[i][j]=a[i][j]+max(x,y);
        }
    }
    printf("%d\n", *max_element(dp[n-1], dp[n-1]+n));
}