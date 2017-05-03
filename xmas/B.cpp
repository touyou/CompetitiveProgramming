#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
using namespace std;
#define INF 20000
int main() {
    int n,m,d,s,t; scanf("%d%d%d%d%d",&n,&m,&d,&s,&t);
    int dp[n][n];
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if (i==j) dp[i][j]=0;
        else dp[i][j]=d*abs(i-j);
    }
    for (int i=0; i<m; i++) {
        int x, y, cost; scanf("%d%d%d",&x,&y,&cost);
        dp[x][y]=cost;
        dp[y][x]=cost;
    }
    for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
//    for (int i=0; i<n; i++) printf("%d ",dp[s][i]);
//    puts("");
    printf("%d\n",dp[s][t]);
}
