#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-10
#define pi 3.14159265358979
using namespace std;
int main() {
    int m, n;
    while (scanf("%d",&m)) {
        if (m==0) break;
        double a=0.0, b=0.0;
        double arg=360.0;
        for (int i=0; i<m-1; i++) {
            int v; scanf("%d",&v);
            a+=sin((double)v/180.0*pi);
            arg-=v;
        }
        a+=sin(arg/180.0*pi);
        arg=360.0;
        scanf("%d",&n);
        for (int i=0; i<n-1; i++) {
            int v; scanf("%d",&v);
            b+=sin((double)v/180.0*pi);
            arg-=v;
        }
        b+=sin(arg/180.0*pi);
        if (abs(a-b)<eps) puts("0");
        else if (a-eps>b) puts("1");
        else puts("2");
    }
}
