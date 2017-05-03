#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string x, y;
    while (cin>>x>>y) {
        int xlen=x.length(), ylen=y.length();
        int dp[xlen+1][ylen+1];
        for (int i=0; i<=xlen; i++) for (int j=0; j<=ylen; j++) dp[i][j]=0;
        for (int i=0; i<xlen; i++) {
            for (int j=0; j<ylen; j++) {
                if (x[i]==y[j]) {
                    dp[i+1][j+1]=dp[i][j]+1;
                } else {
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        printf("%d\n",dp[xlen][ylen]);
    }
}
