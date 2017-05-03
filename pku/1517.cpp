#include <cstdio>
int main()
{
    double dp[10];
    dp[0]=1;
    for (int i=1; i<10; i++) {
        double k=1;
        for (int j=i; j>0; j--) k*=j;
        dp[i]=dp[i-1]+1.0/k;
    }
    printf("n e\n- -----------\n");
    printf("%d %d\n%d %d\n%d %.1f\n",0,1,1,2,2,2.5);
    for (int i=3; i<10; i++) {
        printf("%d %.9f\n",i,dp[i]);
    }
}
