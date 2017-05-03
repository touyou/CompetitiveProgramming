#include <cstdio>
#include <cstring>
using namespace std;
int main() 
{
    int n[6];
    int k=1;
    while(scanf("%d%d%d%d%d%d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5])) {
        if (n[0]==0&&n[1]==0&&n[2]==0&&n[3]==0&&n[4]==0&&n[5]==0) break;
        int sum=0;
        for (int i=0; i<6; i++) sum+=n[i]*(i+1);
        if (sum%2!=0) {
            printf("Collection #%d:\n",k);
            printf("Can't be divided.\n\n");
            k++;
            continue;
        }
        sum/=2;
        int dp[sum*2+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for (int i=0; i<6; i++) {
            if (n[i]==0) continue;
            for (int j=0; j<=sum*2; j++) {
                if (dp[j]>=0) {
                    dp[j]=n[i];
                }
                else if (j<i+1||dp[j-(i+1)]<0) {
                    dp[j]=-1;
                }
                else {
                    dp[j]=dp[j-(i+1)]-1;
                }
            }
        }
        printf("Collection #%d:\n",k);
        if (dp[sum]>=0) {
            printf("Can be divided.\n\n");
        }
        else {
            printf("Can't be divided.\n\n");
        }
        k++;
    }
}

