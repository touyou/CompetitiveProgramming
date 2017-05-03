#include <cstdio>
#include <cmath>
#include <algorithm>
#define EPS 1e-10
using namespace std;
int n, x[200], y[200];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
    int res=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int tit1=y[j]-y[i], tit2=x[j]-x[i];
            int cnt=0;
            for (int k=0; k<n; k++) {
                if ((y[k]-y[i])*tit2==(x[k]-x[i])*tit1) cnt++;
            }
            res=max(res, cnt);
        }
    }
    printf("%d\n",res);
}