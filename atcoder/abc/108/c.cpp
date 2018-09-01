#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n, k; scanf("%d%d", &n, &k);
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) cnt1++;
        if (k % 2 == 0 && i % k == k / 2) cnt2++;
    }
    ll res = cnt1 * cnt1 * cnt1 + cnt2 * cnt2 * cnt2;
    printf("%lld\n", res);
}
