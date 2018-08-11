#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, m; scanf("%lld%lld", &n, &m);
    ll a[100000];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    ll sum[100008];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
    ll rem[100008];
    for (int i = 0; i <= n; i++) rem[i] = sum[i] % m;
    map<ll, ll> rem_cnt;
    rem_cnt[rem[n]] = 1;
    for (int i = n - 1; i >= 0; i--) {
        rem_cnt[rem[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (rem_cnt[rem[i]] >= 2) {
            ans += (rem_cnt[rem[i]] - 1) * rem_cnt[rem[i]] / 2;
            rem_cnt[rem[i]] = 0;
        }
    }
    printf("%lld\n", ans);
}
