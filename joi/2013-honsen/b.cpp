#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;
char s[2013], t[2013];
int dp[2013][2013][2];

int dfs(int i, int j, int k) {
    if (dp[i][j][k]!=-1) return dp[i][j][k];
    int res = 0;
    if (i < m && s[i]=="IO"[k]) res = max(res, dfs(i+1, j, !k) + 1);
    if (j < n && t[j]=="IO"[k]) res = max(res, dfs(i, j+1, !k) + 1);
    return dp[i][j][k] = res;
}

int main() {
    scanf("%d%d",&m,&n);
    scanf("%s%s",s,t);
    
    memset(dp, -1, sizeof(dp));
    
    int res = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            res = max(res, dfs(i, j, 0));
        }
    }
    printf("%d\n", (res==0||res%2==1)?res:res-1);
}