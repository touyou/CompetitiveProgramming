#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n, k, tl;
int t[100], p[100], s[100];
int dp[2][101];
int main() {
    scanf("%d%d%d",&n,&k,&tl);
    for (int i=0; i<n; i++) scanf("%d",&t[i]);
    for (int i=0; i<n; i++) scanf("%d",&p[i]);
    for (int i=0; i<n; i++) scanf("%d",&s[i]);
    vector<vector<int> > gangs(tl+1);
    for (int i=0; i<n; i++) {
        if (gangs[t[i]].empty()) {
            gangs[t[i]]=vector<int>(k+1);
        }
        gangs[t[i]][s[i]]+=p[i];
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<=k; j++) dp[i][j]=-99999;
    }
    dp[0][0]=0;
    for (int i=1; i<=tl; i++) {
        for (int j=0; j<=k; j++) {
            if (j-1>=0) dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j-1]);
            dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j]);
            if (j+1<=k) dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j+1]);
            if (!gangs[i].empty()) dp[i&1][j]+=gangs[i][j];
        }
    }
    int res=0;
    for (int i=0; i<=k; i++) res=max(res,dp[tl&1][i]);
    printf("%d\n",res);
}
