#include <cstdio>
#include <algorithm>
#define eps 1e-6
using namespace std;
int n, m, k, a, b;
int x[5000], y[5000], z[5000];
int xx[5000];
bool C(double mid) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<k; j++) {
            double r=mid*mid*(y[i]*b+z[j]*a)/(y[i]*b);
            if (r<=xx[n-1]) return true;
        }
    }
    return false;
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&x[i]);
        xx[i]=x[i]*x[i];
    }
    sort(xx, xx+n);
    scanf("%d",&m);
    for (int i=0; i<m; i++) scanf("%d",&y[i]);
    scanf("%d",&k);
    for (int i=0; i<k; i++) scanf("%d",&z[i]);
    scanf("%d%d",&a,&b);
    double lb=0.0, ub=5000.0;
    for (int i=0; i<1000; i++) {
        double mid=(lb+ub)/2;
        if (C(mid)) lb=mid;
        else ub=mid;
    }
    printf("%.12f\n",lb);
}