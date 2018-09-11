#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll ma = 1584891;
    ll mb = 3438478;
    ll rx = 32134;
    ll ry = 193127;
    while (rx != ry) {
        if (rx < ry) rx += ma;
        else ry += mb;
    }
    printf("%lld\n", rx);
}
