#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int d[100];
int main() {
    int n,a,b,c; scanf("%d%d%d%d",&n,&a,&b,&c);
    for (int i=0; i<n; i++) scanf("%d",&d[i]);
    sort(d, d+n);
    int sum=c, res=0;
    for (int i=n-1; i>=0; i--) {
        sum+=d[i];
        res=max(res, (int)floor(sum/(a+(n-i)*b)));
    }
    printf("%d\n",res);
}
