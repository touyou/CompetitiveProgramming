#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    ll res = 0;
    for (int b = k+1; b <= n; b++) {
        int div = n / b;
        int pad = n % b;
        res += div * (b - k);   // 余りがk以上はb-k個ずつ
        if (k == 0) res += pad;
        else if (pad >= k) res += (pad - k + 1);
    }
    printf("%lld\n", res);
}

