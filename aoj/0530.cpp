#include <cstdio>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <algorithm>
#define inf INT_MAX/2
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
int n, m;
int main() {
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m) break;
        vector<P> riv[155];
        vector<vector<vector<int> > > dp(155);
        for (int i=0; i<n; i++) {
            int k; scanf("%d",&k);
            riv[i].clear();
            for (int j=0; j<k; j++) {
                int x, d; scanf("%d%d",&x,&d);
                riv[i].push_back(P(x,d));
            }
        }
        for (int i=0; i<n; i++) {
            dp[i].resize(riv[i].size(), vector<int>(m+1,inf));
        }
        for (int i=0; i<riv[0].size(); i++) {
            dp[0][i][0]=0;
        }
        for (int i=0; i<riv[1].size(); i++) {
            dp[1][i][1]=0;
        }
        int res=inf;
        for (int i=0; i<n; i++) {
            for (int j=0; j<riv[i].size(); j++) {
                for (int k=0; k<=m; k++) {
                    if (i+1==n) {
                        res=min(res,dp[i][j][k]);
                    } else {
                        for (int l=0; l<riv[i+1].size(); l++) {
                            dp[i+1][l][k]=min(dp[i+1][l][k],dp[i][j][k]+(int)abs(riv[i][j].f-riv[i+1][l].f)*(riv[i][j].s+riv[i+1][l].s));
                        }
                        if (i<n-1&&k<m) {
                            if (i+2==n) {
                                res=min(res,dp[i][j][k]);
                            } else {
                                for (int l=0; l<riv[i+2].size(); l++) {
                                    dp[i+2][l][k+1]=min(dp[i+2][l][k+1],dp[i][j][k]+(int)abs(riv[i][j].f-riv[i+2][l].f)*(riv[i][j].s+riv[i+2][l].s));
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",res);
    }
}
