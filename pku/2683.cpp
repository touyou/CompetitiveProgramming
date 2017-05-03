#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll tanri(ll s, int y, double rate, int cost) {
    int sum=0;
    for (int i=0; i<y; i++) {
        sum+=floor(s*rate);
        s-=cost;
    }
    return sum+s;
}
ll fukuri(ll s, int y, double rate, int cost) {
    for (int i=0; i<y; i++) {
        int b=floor(s*rate);
        s+=b-cost;
    }
    return s;
}
int main() {
    int m;
    scanf("%d",&m);
    for (int ix=0; ix<m; ix++) {
        ll s;
        int y, n;
        scanf("%lld%d%d",&s,&y,&n);
        ll res=0;
        for (int i=0; i<n; i++) {
            int type, cost;
            double rate;
            scanf("%d%lf%d",&type,&rate,&cost);
            if (type) res=max(res,fukuri(s,y,rate,cost));
            else res=max(res, tanri(s,y,rate,cost));
        }
        printf("%lld\n",res);
    }
}
