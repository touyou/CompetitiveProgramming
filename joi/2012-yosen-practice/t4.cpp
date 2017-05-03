#include <cstdio>
typedef long long ll;
ll n, nb;
int main() {
    nb=1;
    scanf("%lld",&n);
    for (int i=2; i<=n; i++) nb*=i;
    printf("%lld\n",nb);
}
