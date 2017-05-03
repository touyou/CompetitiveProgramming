#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
const int MAX_N=200000;
int n, ni, q, dat[2*MAX_N-1];
int a[MAX_N];
int x[MAX_N], sum[MAX_N];
void init(int n_) {
    n=1;
    while (n<n_) n*=2;
    for (int i=0; i<2*n-1; i++) dat[i]=INT_MIN;
}
void update(int k, int a) {
    k += n-1;
    dat[k]=a;
    while (k>0) {
        k=(k-1)/2;
        dat[k]=max(dat[k*2+1], dat[k*2+2]);
    }
}
int query(int a, int b, int k, int l, int r) {
    if (r<=a||b<=l) return INT_MIN;
    if (a<=l&&r<=b) return dat[k];
    else {
        int vl=query(a,b,k*2+1,l,(l+r)/2);
        int vr=query(a,b,k*2+2,(l+r)/2,r);
        return max(vl,vr);
    }
}
int solve(int l, int r) {
    int a=lower_bound(sum, sum+ni+1, l)-sum;
    int b=lower_bound(sum, sum+ni+1, r)-sum-1;
    // printf("%d %d %d %d %d %d\n",l,r,sum[a],sum[b],a,b);
    if (a==b+1) return r-l+1;
    int aa=sum[a]-l+1;
    int bb=r-sum[b];
    int ret=max(aa,bb);
    return max(ret, query(a+1,b+1,0,0,n));
}
int main() {
    while (scanf("%d",&ni)) {
        if (!ni) break;
        scanf("%d",&q);
        for (int i=0; i<ni; i++) scanf("%d",&a[i]);
        fill(x, x+MAX_N, 0);
        fill(sum, sum+MAX_N, INT_MAX);
        int pos=0, bef=a[0];
        x[0]=1;
        for (int i=1; i<ni; i++) {
            if (bef==a[i]) {
                x[pos]++;
            } else {
                bef=a[i]; pos++;
                x[pos]=1;
            }
        }
        sum[0]=x[0];
        for (int i=1; i<=pos; i++) {
            sum[i]=sum[i-1]+x[i];
        }
        init(++pos);
        for (int i=0; i<pos; i++) update(i,x[i]);
        for (int i=0; i<q; i++) {
            int l, r; scanf("%d%d",&l,&r);
            printf("%d\n",solve(l,r));
        }
    }
}
