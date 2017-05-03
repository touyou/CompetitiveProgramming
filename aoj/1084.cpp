#include <cstdio>
#include <algorithm>
using namespace std;
int c[100];
int calc(int n, int k) {
    int s=0, mt=0;
    for (int i=0; i<=n-k; i++) {
        int temp=1;
        for (int j=0; j<k; j++) temp*=c[i+j];
        mt=max(mt, temp);
    }
    return mt;
}
int main() {
    int n, k;
    while (scanf("%d%d",&n,&k)) {
        if (!n&&!k) break;
        for (int i=0; i<n; i++) scanf("%d",&c[i]);
        int mt=calc(n,k), res=0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                swap(c[i],c[j]);
                res=max(res, calc(n,k));
                swap(c[i],c[j]);
            }
        }
        // printf("%d %d\n",res, mt);
        if (res<mt) puts("NO GAME");
        else printf("%d\n",res-mt);
    }
}