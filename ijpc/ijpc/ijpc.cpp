#include <algorithm>
using namespace std;
int dp[100001][5];
int replace(int N, char S[]) {
    int res=1<<29;
    char ijpc[]="IJPC";
    for (int i=0; i<=N; i++) for (int j=0; j<5; j++) dp[i][j]=res;
    dp[0][0]=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<4; j++) {
            if (S[i]==ijpc[j]) {
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
            } else {
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
            }
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        }
    }
    for (int i=1; i<=N; i++) res=min(res,dp[i][4]);
    return res;
}
