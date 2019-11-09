#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
int r, s, t;
int c[10000001];
ll mod_comb(int n, int k) {
    ll res=1;
    for (int i=n; i>n-k; i--) {
        res *= i;
    }
    for (int i=k; i>0; i--) {
        res /= i;
    }
    return res;
}
void solve() {
    t=INT_MAX;
    for (int i=1; i*i<=s; i++) {
        if (s%i==0&&c[i]!=-1&&c[s/i]!=-1) {
            t=min(t, c[i]+c[s/i]);
        }
    }
    if (t==INT_MAX) t=0;
}
int main() {
    scanf("%d",&r);
    memset(c, -1, sizeof(c));
    for (int i=1; i<12; i++) {
        for (int j=0; j<=i/2; j++) {
            ll x=mod_comb(i,j);
            if (x>10000000) continue;
            if (c[x]==-1) {
                c[x]=i;
            } else {
                c[x]=min(c[x], i);
            }
            // printf("%d\n",x);
        }
    }
    for (int i=1; i<10000001; i++) {
        if (c[i]==-1) c[i]=i+1;
    }
    for (int ix=1; ix<=r; ix++) {
        scanf("%d",&s);
        solve();
        printf("Case #%d: %d\n",ix,t);
    }
}
