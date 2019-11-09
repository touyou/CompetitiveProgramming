#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
/*
100万円以下の金額が与えられる。日本の硬貨／紙幣で支払いをする時、支払う合計枚数の最小値を出力しなさい
*/
/*
1<=n<=10^7
1,5,10,50,100,1000,5000,10000
*/
int dp[1000001];
int coin[8]={1,5,10,50,100,1000,5000,10000};
int main() {
    fill(dp, dp+1000001, INT_MAX/2);
    dp[0]=0;
    for (int i=0; i<8; i++) dp[coin[i]]=1;
    for (int i=2; i<1000001; i++) {
        for (int j=0; j<8; j++) {
            if (i-coin[j]>=0) {
                dp[i]=min(dp[i], dp[i-coin[j]]+1);
            } else break;
        }
    }
    int n;
    while (scanf("%d",&n)) {
        if (n==-1) break;
        printf("%d\n",dp[n]);
    }
}
