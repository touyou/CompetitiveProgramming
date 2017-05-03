#include <cstdio>
int main()
{
    long long int t, n, m;
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%lld%lld", &n, &m);
        long long int res = (n + m) * (m - n + 1) / 2;
        printf("Scenario #%d:\n%lld\n\n", i, res);
    }
}
