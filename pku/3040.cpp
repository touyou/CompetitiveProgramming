#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct deno {
    int v, b;
    bool operator<(const deno& de)const{
        return v<de.v;
    }
};
int n, c;
ll res=0;
deno des[20];
int main() {
    scanf("%d%d",&n,&c);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&des[i].v,&des[i].b);
    }
    sort(des, des+n);
    for (int i=0; i<n; i++) {
        if (des[i].v>=c) {
            res+=des[i].b;
        } else {
            int less=c-des[i].v;
            int lb=i, ub=n;
            while (ub-lb>1) {
                int mid=(lb+ub)/2;
                if (des[mid].v>=less) {
                    ub=mid;
                } else {
                    lb=mid;
                }
            }
            if (lb==i) {
                res+=des[i].b/2;
            } else {
                for (int j=lb; j<n; j++) {
                    if (des[j].b>des[i].b) {
                        des[j].b-=des[i].b;
                        res+=des[i].b;
                        des[i].b=0;
                        break;
                    } else {
                        des[i].b-=des[j].b;
                        res+=des[j].b;
                        des[j].b=0;
                    }
                }
                if (des[i].b!=0) {
                    res+=des[i].b/(c/des[i].b);
                }
            }
        }
    }
    printf("%lld\n",res);
}
