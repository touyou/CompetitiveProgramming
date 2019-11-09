#include <cstdio>

int main()
{
    int n;
    long long int p;
    while (scanf("%d%lld",&n,&p)) {
        int res = 0;
        while (p > 1) {
            p /= n;
            res++;
        }
        printf("%d\n", res);
    }
}
