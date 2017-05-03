#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
const int MAX_N = 1 << 17;
int n, dat[2*MAX_N-1], dat2[2*MAX_N-1];
void init(int n_) {
    n=1;
    while (n<n_) n*=2;
    for (int i=0; i<2*n-1; i++) {
        dat[i]=INT_MAX;
        dat2[i]=INT_MIN;
    }
}
void update(int k, int a) {
    k += n-1;
    dat[k]=a;
    dat2[k]=a;
    while (k>0) {
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
        dat2[k]=max(dat2[k*2+1],dat2[k*2+2]);
    }
}
int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INT_MAX;
    if (a <= l && r <= b) return dat[k];
    else {
        int vl=query(a,b,k*2+1,l,(l+r)/2);
        int vr=query(a,b,k*2+2,(l+r)/2,r);
        return min(vl, vr);
    }
}
int query2(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INT_MIN;
    if (a <= l && r <= b) return dat2[k];
    else {
        int vl=query2(a,b,k*2+1,l,(l+r)/2);
        int vr=query2(a,b,k*2+2,(l+r)/2,r);
        return max(vl, vr);
    }
}
int main() {
    int nx,q; scanf("%d%d",&n,&q);
    nx=n;
    init(n);
    for (int i=0; i<nx; i++) {
        int cow; scanf("%d",&cow);
        update(i,cow);
    }
    for (int i=0; i<q; i++) {
        int a, b; scanf("%d%d",&a,&b);
        int r1=query(a-1,b,0,0,n);
        int r2=query2(a-1,b,0,0,n);
        printf("%d\n",r2-r1);
    }
}
