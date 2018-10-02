#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pii = pair<int, pi>;

int main() {
    int n; scanf("%d", &n);
    int x[1000], y[1000];
    vector<pii> lis;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", x+i, y+i);
        lis.push_back(pii(x[i]+y[i], pi(x[i], y[i])));
    }
    sort(lis.rbegin(), lis.rend());

}
