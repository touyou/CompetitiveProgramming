#include <cstdio>
#include <cmath>
int n, k;
bool C(int v) {
    int sum=0;
    while (v!=0) {
        sum+=v;
        v/=k;
    }
//    printf("%d %d\n",v,sum);
    if (sum>=n) return true;
    else return false;
}
int main() {
    scanf("%d%d",&n,&k);
    int l=0, r=n+1;
    while (r-l>1) {
        int mid=(l+r)/2;
        if (C(mid)) {
            r=mid;
        } else {
            l=mid;
        }
    }
    printf("%d\n",r);
}
