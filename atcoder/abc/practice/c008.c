#include <stdio.h>
typedef long long ll;

int main() {
    ll table[101];
    table[0] = 1;
    for (ll i = 1; i < 101; i++) table[i] = table[i-1] * i;
    int n, c[128]; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", c + i);
    int cnt[128];
    for (int i = 0; i < n; i++) {
        cnt[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (c[i] % c[j] == 0) cnt[i]++;
        }
    }
    ll sumall = 1;
    for (ll i = 1; i <= n; i++) sumall *= i;
    //for (int i = 0; i < n; i++) {
    //    int cnt = 1;
    //    if (c[i] == -1) continue;
    //    for (int j = i + 1; j < n; j++) {
    //        if (c[i] == c[j]) {
    //            cnt++;
    //            c[j] = -1;
    //        }
    //    }
    //    c[i] = cnt;
    //    sumall /= table[cnt];
    //}
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        //if (c[i] == -1) continue;
        if (cnt[i] == 0) {
            ret += sumall;
            continue;
        }
        for (int r = 0; r <= cnt[i]; r+=2) {
            for (int l = 0; l < n - cnt[i]; l++) {
                ll tmp = 1;
                if (r != 0) tmp *= table[cnt[i]] / table[r];
                if (l != 0) tmp *= table[n - cnt[i] - 1] / table[l];
                tmp *= table[r + l] * table[n - r - l - 1];
                //for (int j = 0; j < n; j++) {
                //    if (c[j] == -1) continue;
                //    if (i == j) tmp /= table[c[j]-1];
                //    else tmp /= table[c[j]];
                //}
                ret += tmp;
            }
        }
        printf("%lld %lld %d\n", sumall, ret, i);
    }
    printf("%lf\n", (double)ret/(double)sumall);
    return 0;
}
