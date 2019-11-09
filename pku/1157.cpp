#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=-100000;
int table[102][102];
int dp[102][102];
int main() {
    int f, v;
    for (int i=0; i<102; i++) for (int j=0; j<102; j++) dp[i][j]=INF;
    scanf("%d%d",&f,&v);
    for (int i=0; i<f; i++) for (int j=0; j<v; j++) scanf("%d",&table[i][j]);
    for (int i=0; i<v-f+1; i++) dp[0][i]=table[0][i];
    for (int i=1; i<f; i++) {
        for (int j=i; j<v-f+1+i; j++) {
            for (int k=0; k<j; k++) if (dp[i-1][k]!=INF)
                dp[i][j]=max(dp[i][j],dp[i-1][k]+table[i][j]);
        }
    }
    int res=INF;
    for (int i=0; i<v; i++) res=max(res, dp[f-1][i]);
    printf("%d\n",res);
}
