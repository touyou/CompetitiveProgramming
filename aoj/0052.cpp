#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    const ll INF = 2000000000;
    vector<ll> five;
    for (ll i=5; i<=INF; i*=5) five.push_back(i);
    ll n;
    while (scanf("%lld",&n)) {
        if (!n) break;
        ll res=0;
        for (int i=0; i<five.size()&&five[i]<=n; i++)
            res+=n/five[i];
        printf("%lld\n",res);
    }
}
