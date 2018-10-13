#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;
int main() {
    int n; scanf("%d", &n);
    ll a[100000];
    for (int i = 0; i < n; i++) scanf("%lld", a+i);
    ll count[100000][100000] = {0};
    ll num[100000] = {0};
    count[0][0] = 1;
    num[0] = 1;
    for (int i = 0; i < n; i++) {
        ll n = 0;
        for (int j = 0; j < i; j++) { // j文字目に1を置いた時？
            ll lnum = j == 0 ? 1 : num[j - 1];
            ll rnum = j == i-1 ? 1 : num[i - j + 1];
            n += lnum * rnum;
            for (int k = 0; k < i; k++) {
                if (j == k) count[i][j] = (count[i][j] + lnum * rnum) % mod;
                else if (k < j) {
                    count[i][j] = (count[i][j] + rnum * count[lnum][k] + lnum * rnum) % mod;
                } else {
                    count[i][j] = (count[i][j] + lnum * count[rnum][k-j-1] + lnum * rnum) % mod;
                }
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + a[i] * count[n-1][i]) % mod;
    }
    printf("%lld\n", sum);
}
