#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a, b, c, x, y;
    scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &x, &y);
    ll bara = a * x + b * y;
    ll matome;
    if (x < y) {
        matome = min((y - x) * b + x * 2 * c, y * 2 * c);
    } else {
        matome = min((x - y) * a + y * 2 * c, x * 2 * c);
    }
    printf("%lld\n", min(bara, matome));
}
