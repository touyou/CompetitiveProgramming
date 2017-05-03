// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2427
// 前の馬車よりも遅いスピードであれば1分後に発車する
// 間隔さえ決めれば良い
// 各地点に何分後につくか
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist, d[6], t[5][6];
int n, m, s[5];
int main() {
    scanf("%lld%d", &dist, &n);
    for (int i=0; i<n; i++) scanf("%d", &s[i]);
    scanf("%d", &m);
    for (int i=0; i<m; i++) scanf("%lld", &d[i]);
    d[m] = dist;
    sort(d, d+m+1);
    for (int i=0; i<n; i++) for (int j=0; j<m+1; j++) t[i][j] = s[i] * d[j];
}
