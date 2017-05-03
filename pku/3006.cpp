#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a, d, n;
    bool isprime[1000001];
    fill(isprime, isprime+1000001, true);
    isprime[0]=isprime[1]=false;
    for (int i=2; i<1000001; i++) {
        if (isprime[i]) {
            for (int j=i+i; j<1000001; j+=i) isprime[j]=false;
        }
    }
    while (scanf("%d%d%d", &a, &d, &n)) {
        if (a == 0 && d == 0 && n == 0) break;
        int cnt=0;
        int i;
        for (i=a; cnt!=n; i+=d) if (isprime[i]) cnt++;
        printf("%d\n", i-d);
    }
}
