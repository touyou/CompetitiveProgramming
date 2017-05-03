// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2607
//
#include <bits/stdc++.h>
using namespace std;
int n, d, x;
int p[10][10];
int dp[100001];
int s, s2;
int main() {
    scanf("%d%d%d",&n,&d,&x);
    for (int i=0; i<d; i++) for (int j=0; j<n; j++) scanf("%d", &p[i][j]);
    int res = x;
    for (int i=0; i<d-1; i++) {
        memset(dp, 0, sizeof(dp));
        for (int j=0; j<res+1; j++) dp[j]=j;
        int tmp = res;
        for (int j=0; j<n; j++) {
            for (int k=p[i][j]; k<res+1; k++) {
                dp[k] = max(dp[k], dp[k-p[i][j]]+p[i+1][j]);
                tmp = max(tmp, dp[k]);
            }
        }
        res = tmp;
    }
    printf("%d\n",res);
}
