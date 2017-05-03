#include <cstdio>
#include <algorithm>
using namespace std;
int n,q;
int w[10000], v[10000];
int dp[10005];
int main() {
    scanf("%d%d",&n,&q);
    for (int i=0; i<n; i++) scanf("%d%d",&w[i],&v[i]);
    for (int i=0; i<=10000; i++) dp[i]=0;
    for (int i=0; i<n; i++) {
        for (int j=10000; j>=w[i]; j--) {
            dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    for (int ix=0; ix<q; ix++) {
        int x; scanf("%d",&x);
        if (x==0) {
            int a; scanf("%d",&a);
            printf("%d\n",dp[a]);
        } else {
            int a, b, c; scanf("%d%d%d",&a,&b,&c);
            w[a-1]=b;
            v[a-1]=c;
            for (int i=0; i<=10000; i++) dp[i]=0;
            for (int i=0; i<n; i++) {
                for (int j=10000; j>=w[i]; j--) {
                    dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
                }
            }
        }
    }
}
