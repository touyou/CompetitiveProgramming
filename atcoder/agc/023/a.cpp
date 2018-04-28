#include <cstdio>
#include <map>
typedef long long ll;
typedef std::map<ll, ll> mll;
int main() {
    int n;
    ll a[200000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll res = 0;
    ll sum = 0;
    std::map<ll, ll> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (mp.find(sum) != mp.end()) {
            res += mp[sum];
            mp[sum]++;
        } else {
            mp[sum] = 1;
        }
    }
    printf("%lld\n", res);
}
