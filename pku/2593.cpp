#include <cstdio>
#include <vector>
using namespace std;
int main() 
{
    int N;
    while (scanf("%d", &N) && N != 0) {
        vector<vector<int> > dp;
        for (int i=0; i<N; i++) {
            dp.push_back(vector<int>(N-i));
            scanf("%d", &dp[i][0]);
        }
        for (int i=0; i<N; i++) {
            for (int j=1; j<dp[i].size(); j++) {
                dp[i][j] = dp[i][j-1] + dp[i+j][0];
            }
        }
        int res = dp[0][0] + dp[1][0];
        for (int i=0; i<N-1; i++) {
            for (int j=0; j<dp[i].size(); j++) {
                int tmp = dp[i][j];
                for (int k=i+j+1; k<N; k++) {
                    for (int l=0; l<dp[k].size(); l++) {
                        if (tmp+dp[k][l] > res) res = tmp + dp[k][l];
                    }
                }
            }
        }
        printf("%d\n", res);
    }
}

