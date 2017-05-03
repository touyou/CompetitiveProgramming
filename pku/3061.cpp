#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int t, n;
ll s;
int seq[100000];
int main() {
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        scanf("%d%lld",&n,&s);
        for (int i=0; i<n; i++) scanf("%d",&seq[i]);
        int res=100001, lb=0, ub=0;
        ll sum=0;
        while (true) {
            while (sum<s&&ub<n) sum+=seq[ub++];
            if (sum<s) break;
            res=min(res,ub-lb);
            sum-=seq[lb++];
        }
        if (res>n) res=0;
        printf("%d\n",res);
    }
}
