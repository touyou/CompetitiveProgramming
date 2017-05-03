#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    while (scanf("%d", &n)!=EOF) {
        int p[n];
        int dp[n];
        for (int i=0; i<n; i++) scanf("%d", &p[i]);
        fill(dp, dp+n, INT_MAX);
        for (int i=0; i<n; i++) {
            *lower_bound(dp, dp+n, p[i]) = p[i];
        }
        printf("%d\n", lower_bound(dp, dp+n, INT_MAX) - dp);
    }
}

