#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[40000], b[40000];
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) scanf("%d",&a[i]);
        for (int i=0; i<n; i++) scanf("%d",&b[i]);
        sort(a,a+n); sort(b,b+n);
        int win=0, mon=0;
        for (int i=n-1; i>=0; i--) {
            mon++;
            if (a[i]>b[i]) win++;
            if (mon*0.5<win) break;
        }
        if (mon>=n) puts("NA");
        else printf("%d\n",mon);
    }
}
