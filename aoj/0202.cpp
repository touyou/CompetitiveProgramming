#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1000001
using namespace std;
int n, x;
int isprime[MAX];
int w[30];
int dp[MAX];
int main() {
    memset(isprime, 1, sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for (int i=2; i<MAX; i++) {
        if (isprime[i]) {
            for (int j=i*2; j<MAX; j+=i) isprime[j]=0;
        }
    }
    while (scanf("%d%d",&n,&x)) {
        if (n==0&&x==0) break;
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++) scanf("%d",&w[i]);
        dp[0]=1;
        for (int i=0; i<=x; i++) {
            if (dp[i]) {
                for (int j=0; j<n; j++) {
                    if (i+w[j]<=x) dp[i+w[j]]=1;
                }
            }
        }
        int res=-1;
        for (int i=x; i>0; i--) {
            if (dp[i]&&isprime[i]) {
                res=i;
                break;
            }
        }
        if (res==-1) puts("NA");
        else printf("%d\n",res);
    }
}
