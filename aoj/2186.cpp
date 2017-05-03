// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2186
// 最初またたびの置かれる位置を勘違いしていたので少し手間取った
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int dp[16][16];
int t, gx, gy, p, a, b, c, d;
int main() {
    scanf("%d", &t);
    for (int r=0; r<t; r++) {
        scanf("%d%d%d",&gx,&gy,&p);
        vector<P> maps[16][16];
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<p; i++) {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            maps[a][b].push_back(P(c,d)); maps[c][d].push_back(P(a,b));
        }
        dp[0][0] = 1;
        for (int i=0; i<=gx; i++) {
            for (int j=0; j<=gy; j++) {
                if (i > 0) {
                    dp[i][j] += dp[i-1][j];
                    for (int k=0; k<maps[i][j].size(); k++) if (maps[i][j][k].first==i-1&&maps[i][j][k].second==j) {
                        dp[i][j] -= dp[i-1][j];
                        break;
                    }
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j-1];
                    for (int k=0; k<maps[i][j].size(); k++) if (maps[i][j][k].first==i&&maps[i][j][k].second==j-1) {
                        dp[i][j] -= dp[i][j-1];
                        break;
                    }
                }
                // printf("%d ", dp[i][j]);
            }
            // puts("");
        }
        if (dp[gx][gy]==0) {
            puts("Miserable Hokusai!");
        } else {
            printf("%d\n",dp[gx][gy]);
        }
    }
}
