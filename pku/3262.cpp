#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct cow { int t, d; };
bool comp(const cow& a, const cow& b) {
    return a.d>b.d||(a.d==b.d&&a.t<b.t);
}
cow c[100000];
int main() {
    int n, sum=0;
    ll res=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&c[i].t,&c[i].d);
        sum+=c[i].d;
    }
    sort(c, c+n, comp);
    for (int i=0; i<n; i++) {
        sum-=c[i].d;
//        printf("%d %d\n",c[i].t,c[i].d);
        res+=2*(ll)c[i].t*(ll)sum;
    }
    printf("%lld\n",res);
}
