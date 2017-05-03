// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2182
// dp[i][j] := A(i,j)
// dp[i][j] = (n*10+s mod 11 = (n mod 11)*10+s)
// 10 = 10, 20 = 9, 30 = 8, 40 = 7, ... 100 = 1
#include <bits/stdc++.h>
using namespace std;
int dp[80000][11];
string num;
int main() {
    while(cin>>num && num!="0") {
        memset(dp, 0, sizeof(dp));
        dp[0][num[0]-'0'] = 1;
        int res = dp[0][0];
        for (int i=1; i<num.length(); i++) {
            if (num[i]!='0') dp[i][num[i]-'0'] = 1;
            for (int j=0; j<11; j++) {
                // printf("%d %d\n",(j*10+int(num[i]-'0'))%11,int(num[i]-'0'));
                dp[i][(j*10+int(num[i]-'0'))%11] += dp[i-1][j];
            }
            res += dp[i][0];
        }
        // for (int i=0; i<num.length(); i++) {
        //     for (int j=0; j<11; j++) printf("%d ",dp[i][j]);
        //     puts("");
        // }
        printf("%d\n",res);
    }
}
