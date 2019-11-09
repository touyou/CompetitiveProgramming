#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int prime[10000];
    int pnum = 0;
    bool isprime[10001];
    fill(isprime, isprime+10001, true);
    isprime[0]=isprime[1]=false;
    for (int i=2; i<10001; i++) {
        if (isprime[i]) {
            prime[pnum++] = i;
            for (int j=i+i; j<10001; j+=i) isprime[j]=false;
        }
    }
    int num;
    while (scanf("%d", &num)) {
        if (num == 0) break;
        int res = 0;
        for (int i=0; prime[i]<=num; i++) {
            int sum = prime[i];
            for (int j=i+1; j<10000; j++) {
                if (sum == num) {
                    res++;
                    break;
                }
                if (sum > num) break;
                sum += prime[j];
            }
        }
        printf("%d\n", res);
    }
}
