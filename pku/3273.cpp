#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
ll money[100000];
bool C(ll cost) {
    ll sum=0, mon=1;
    for (int i=0; i<n; i++) {
        if (sum+money[i]>cost) {
            sum=money[i];
            mon++;
        } else {
            sum+=money[i];
        }
    }
    if (mon<=m) return true;
    else return false;
}
int main() {
    scanf("%d%d",&n,&m);
    ll l=0, u=1;
    for (int i=0; i<n; i++) {
        scanf("%lld",&money[i]);
        l=max(l,money[i]);
        u+=money[i];
    }
    while (u>l) {
        int mid=(l+u)/2;
        if (C(mid)) u=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
}
