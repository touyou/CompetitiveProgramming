#include <cstdio>
#include <cmath>
using namespace std;
int n, k;
double l[10000];
bool C(double x) {
    int cnt=0;
    for (int i=0; i<n; i++) {
        cnt+=int(l[i]/x);
    }
    return cnt>=k;
}
int main() {
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) scanf("%lf",&l[i]);
    double lb=0.0, ub=100001.0;
    for (int i=0; i<100; i++) {
        double mid=(lb+ub)/2;
        if (C(mid)) {
            lb=mid;
        } else {
            ub=mid;
        }
    }
    printf("%.2f\n",floor(ub*100)/100);
}
