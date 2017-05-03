#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int prime[100000];
    int pnum = 0;
    bool isprime[1299710];
    fill(isprime, isprime+1299710, true);
    isprime[0]=isprime[1]=false;
    for (int i=2; i<1299710; i++) {
        if (isprime[i]) {
            prime[pnum++] = i;
            for (int j=i+i; j<1299710; j+=i) isprime[j]=false;
        }
    }
    int num;
    while (scanf("%d", &num)) {
        if (num == 0) break;
        if (isprime[num]||num<2) {
            printf("0\n");
            continue;
        }
        int res;
        for (int i=0; i<100000; i++) {
            if (prime[i] < num ) {
                res = prime[i+1] - prime[i];
            }
        }
        printf("%d\n", res);
    }
}
