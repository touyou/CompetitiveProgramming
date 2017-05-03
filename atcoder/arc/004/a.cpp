#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int x[100], y[100];
double calc(int i, int j) {
    return sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(double)(y[i]-y[j])*(y[i]-y[j]));
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    double ans=0.0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans=max(ans, calc(i,j));
        }
    }
    printf("%.10f\n",ans);
}