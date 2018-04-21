#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll dp[100001], mdp[100001], odp[100001], omdp[100001], x[100000], v[100000], ox[100000];
int main() {
    ll c;
    scanf("%lld%lld", &n, &c);
    ll res = 0;
    ll now = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &v[i]);
        ox[i] = c - x[i];
    }
    // 順に回る時
    for (int i = 0; i < n; i++) {
        now += v[i];
        dp[i] = now - x[i];
        if (i == 0) mdp[i] = dp[i];
        else mdp[i] = max(mdp[i-1], dp[i]);
        res = max(res, now - x[i]);
    }
    now = 0;
    // 逆に回る時
    for (int i = n-1; i >= 0; i--) {
        now += v[i];
        odp[i] = now - ox[i];
        if (i == n-1) omdp[i] = odp[i];
        else omdp[i] = max(omdp[i+1], odp[i]);
        res = max(res, now - ox[i]);
    }
    // 往復する場合
    // 1 2 3 4 5 6 7 8 9 10
    now = 0;
    for (int i = n-1; i > 1; i--) {
        now += v[i];
        res = max(res, mdp[i-1] + now - 2 * ox[i]);
    }
    now = 0;
    for (int i = 0; i < n - 1; i++) {
        now += v[i];
        res = max(res, omdp[i+1] + now - 2 * x[i]);
    }
    printf("%lld\n", res);
}
