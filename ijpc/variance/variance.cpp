#include "variance.h"
#include <cstring>
typedef long long ll;

int N;
int *A;

struct Bit {
    ll bit[1<<17];
    Bit(){ memset(bit,0,sizeof(bit)); };
    ll sum(int i) {
        ll s=0;
        while (i>0) {
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }
    void add(int i, ll x) {
        while (i<=(1<<17)) {
            bit[i]+=x;
            i+=i&-i;
        }
    }
};

Bit b, c;

void init(int n, int *a) {
    N = n;
    A = a;
    for (int i=0; i<N; i++) {
        b.add(i+1,A[i]);
        c.add(i+1,A[i]*A[i]);
    }
}

int variance(int i, int j) {
    ll X=b.sum(j+1)-b.sum(i), B=c.sum(j+1)-c.sum(i), n=j-i+1;
    return int((B*n-X*X)/(ll)(n*n));;
}

void update(int i, int x) {
    b.add(i+1,x-A[i]);
    c.add(i+1,x*x-A[i]*A[i]);
    A[i]=x;
}

