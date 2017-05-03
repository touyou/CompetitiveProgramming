#include <cstdio>
#include <vector>
using namespace std;
#define MOD 100000
typedef long long ll;
typedef vector<ll> vi;
int main() {
    int a, b;
    vector<vi> dp;
    for (int i=1; i<=1000; i++) dp.push_back(vi(i,1));
    for (int i=0; i<1000; i++) dp.push_back(vi(1000,1));
    for (int i=1; i<2000; i++) {
        dp[i][0]=i+1;
        if (i<1000) {
            dp[i][i]=1;
            for (int j=1; j<dp[i].size()-1; j++) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        } else {
            for (int j=1; j<dp[i].size(); j++) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    while (scanf("%d%d",&a,&b)) {
        if (a==0&&b==0) break;
        else if (a==0) puts("1");
        else if (a>b) puts("0");
        else printf("%d\n",(dp[a+b-1][a-1]-dp[a+b-1][a-2])%MOD);
    }
}