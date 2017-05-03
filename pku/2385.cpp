#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t, w;
int fall[1000];
int dp[1000][31];
/*
dp[i][j]=i番目までにj回移動した時の最大値(?)
dp[0][even]=1(fall[0]=0) 0(fall[0]=1)
dp[0][odd]=0(fall[0]=0) 1(fall[0]=1)
dp[i][j]=max(dp[i-1][k]+a)
*/
int main() {
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&t,&w);
    for (int i=0; i<t; i++) scanf("%d",&fall[i]);
    for (int i=0; i<t; i++) fall[i]--;
    for (int i=0; i<w; i++) {
        if (i%2==fall[0]) dp[0][i]=1;
        else dp[0][i]=0;
    }
    for (int i=1; i<t; i++) for (int j=0; j<=w; j++) {
        int pos=j%2;
        int a;
        if (pos==fall[i]) a=1;
        else a=0;
        for (int k=0; k<=j; k++) {
            dp[i][j]=max(dp[i][j],dp[i-1][k]+a);
        }
        // printf("%d%c",dp[i][j],j==w-1?'\n':' ');
    }
    int res=0;
    for (int i=0; i<=w; i++) {
        res=max(res,dp[t-1][i]);
    }
    printf("%d\n",res);
}
