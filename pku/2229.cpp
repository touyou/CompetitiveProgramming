#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    vector<int> p;
    for (int i=2; i<=1000000; i*=2) p.push_back(i);
    int n, cnt=0; scanf("%d",&n);
    ll dp[1000001];
    dp[1]=1;
    for (int i=2; i<=n; i++) {
        dp[i]=0;
        if (i%2==0) dp[i]+=dp[i/2];
        dp[i]+=dp[i-1];
        dp[i]%=1000000000;
    }
    printf("%lld\n",dp[n]);
}
