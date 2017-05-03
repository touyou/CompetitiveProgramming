#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, v[2000];
ll dp[2001][2001];
ll solve(int f, int t) {
    int len=n-(t-f-1);
    if (dp[f][t]) return dp[f][t];
    if (len==n) return n*v[f];
    return dp[f][t]=max(solve(f+1,t)+len*v[f],solve(f,t-1)+len*v[t-1]);
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&v[i]);
    printf("%lld\n",solve(0,n));
}
