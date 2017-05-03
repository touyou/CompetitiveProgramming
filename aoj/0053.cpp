#include <cstdio>
#include <cstring>
int main()
{
    int isprime[1000000];
    memset(isprime, 0, sizeof(isprime));
    int prime[10000], cnt=0;
    for (int i=2; cnt<10000; i++)
        if (isprime[i]==0) {
            prime[cnt++]=i;
            for (int j=i+i; j<1000000; j+=i)
                isprime[i]=1;
        }
    int n;
    while (scanf("%d", &n) && n != 0) {
        int sum = 0;
        for (int i=0; i<n; i++) sum += prime[i];
        printf("%d\n", sum);
    }
}
