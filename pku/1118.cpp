#include <cstdio>
#include <algorithm>
using namespace std;
int x[700], y[700];
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
        int res=0, cnt;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                cnt=2;
                for (int k=j+1; k<n; k++) {
                    if (k==i||k==j) continue;
                    cnt+=((y[j]-y[i])*(x[k]-x[i])==(y[k]-y[i])*(x[j]-x[i]));
                }
                res=max(res,cnt);
            }
        }
        printf("%d\n",res);
    }
}