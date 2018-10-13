#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    ll lcm = n * m / __gcd(n, m);
    ll ln = lcm / n, lm = lcm / m;
    ll llcm = ln * lm / __gcd(ln, lm);
    bool flag = true;
    for (ll i = 0; i < lcm; i += llcm) {
        if (s[i / ln] != t[i / lm]) flag = false;
    }
    if (flag) printf("%lld\n", lcm);
    else puts("-1");
}
