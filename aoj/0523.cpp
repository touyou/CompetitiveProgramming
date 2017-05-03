#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (n==0) break;
        int taro[n], hana[n], t=0, h=0, ut=n, uh=n, turn=1;
        bool usedt[n], usedh[n];
        for (int i=0; i<n; i++) scanf("%d",&taro[i]);
        sort(taro, taro+n);
        fill(usedt, usedt+n, true);
        fill(usedh, usedh+n, true);
        for (int i=1; i<=2*n; i++) {
            if (taro[t]==i) t++;
            else hana[h++]=i;
        }
        // for (int i=0; i<n; i++) printf("%d %d\n",taro[i],hana[i]);
        t=0; h=0;
        while (ut>0&&uh>0) {
            if (turn) {
                bool flag=true; ut--;
                usedt[t]=false;
                // printf("%d\n",taro[t]);
                for (;h<n; h++) if (taro[t]<hana[h]&&usedh[h]) {
                    flag=false;
                    turn=0;
                    break;
                }
                if (flag) {
                    for (t=0; t<n; t++) if (usedt[t]) break;
                    h=0;
                }
            } else {
                bool flag=true; uh--;
                usedh[h]=false;
                // printf("%d\n",hana[h]);
                for (;t<n; t++) if (hana[h]<taro[t]&&usedt[t]) {
                    flag=false;
                    turn=1;
                    break;
                }
                if (flag) {
                    for (h=0; h<n; h++) if (usedh[h]) break;
                    t=0;
                }
            }
        }
        printf("%d\n%d\n",uh,ut);
    }
}
