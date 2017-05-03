// ソートして愚直に計算
// Accepted
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010];
int main() {
    while (scanf("%d", &n)) {
        if (n==0) break;
        for (int i=0; i<n; i++) scanf("%d",&a[i]);
        sort(a, a+n);
        int res = 1000001;
        for (int i=1; i<n; i++) {
            res = min(res, a[i]-a[i-1]);
        }
        printf("%d\n",res);
    }
}
