#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct block { int a, h, c; };
bool comp(const block& a, const block& b) {
    return a.a<b.a;
}
int k;
int dp[40001];
block b[400];
int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d",&k);
    for (int i=0; i<k; i++) scanf("%d%d%d",&b[i].h,&b[i].a,&b[i].c);
    sort(b, b+k, comp);
    int res=b[k-1].a;
    dp[0]=0;
    for (int i=0; i<k; i++) {
        for (int j=0; j<=b[i].a; j++) {
            if (dp[j]>=0) dp[j]=b[i].c;
            else if (j<b[i].h||dp[j-b[i].h]<=0) dp[j]=-1;
            else dp[j]=dp[j-b[i].h]-1;
            // printf("%d%c",dp[j],j==b[i].a?'\n':' ');
        }
    }
    // for (int i=0; i<=res; i++) printf("%d%c",dp[i],i%10==0?'\n':' ');
    while (dp[res]<0) res--;
    printf("%d\n",res);
}
