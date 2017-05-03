// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=10029
// 一応通してなかったので埋めた。ソートするだけ。
#include <bits/stdc++.h>
using namespace std;
int n, t;
vector<int> v;
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (int i=0; i<n-1; i++) {
        printf("%d ",v[i]);
    }
    printf("%d\n",v[n-1]);
}
