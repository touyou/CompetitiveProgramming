#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int h, res;
int isp[1000002];
int hpr[1000002];
int co[1000002];
int dp[1000002];
int main() {
    fill(isp, isp+1000002, 1);
    isp[0]=isp[1]=0;
    int pos=0;
    for (int i=5; i<1000002; i+=4) {
        if (isp[i]) {
            hpr[pos++]=i;
            for (int j=i*2; j<1000002; j+=i) isp[j]=0;
        }
    }
    for (int i=0; i<pos; i++) {
        for (int j=0; j<=i; j++) {
            if (hpr[i]*hpr[j]>1000002) break;
            co[hpr[i]*hpr[j]]=1;
        }
    }
    for (int i=0; i<1000001; i++) {
        dp[i+1]=dp[i]+co[i+1];
    }
    while (scanf("%d",&h)) {
        if (!h) break;
        printf("%d %d\n",h,dp[h]);
    }
}
