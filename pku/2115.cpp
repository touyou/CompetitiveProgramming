#include <cstdio>
#include <cmath>
#include <climits>
typedef long long ll;
int main() {
    ll a,b,c,k;
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k)) {
        if (!(a&&b&&c&&k)) break;
        ll mod = (ll)pow(2.0, (double)k);
        if (a>b) b+=mod;
        if ((b-a)%c==0) {
            printf("%lld\n",(b-a)/c);
        } else {
            printf("FOREVER\n");
        }
    }
}
