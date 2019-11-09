#include <cstdio>
int dp[1121][15];
bool isprime[1121];
void init() {
    for (int i=0; i<1121; i++) isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for (int i=2; i*i<1121; i++) if (isprime[i]) {
        for (int j=2*i; j<1121; j+=i) isprime[j]=false;
    }

    for (int i=2; i<1121; i++) if (isprime[i]) dp[i][1]=1;
    for (int i=4; i<1121; i++) {
        int n=i/2, m=i-n;
        while (n>1) {
            if (isprime[n]&&isprime[m]&&n!=m) dp[i][2]++;
            n--; m++;
        }
}
int main() {
    int n, k;
    init();
    while (scanf("%d%d",&n,&k)) {
        if (!n&&!k) break;
        printf("%d\n",dp[n][k]);
    }
}
