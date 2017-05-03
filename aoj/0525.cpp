#include <cstdio>
#include <algorithm>
using namespace std;
int osen[10][10000];
int main() {
    int r, c;
    while (scanf("%d%d",&r,&c)) {
        if (!r&&!c) break;
        for (int i=0; i<r; i++) for (int j=0; j<c; j++) {
            scanf("%d", &osen[i][j]);
        }
        int res=0;
        for (int S=0; S < 1<<r; S++) {
            for (int i=0; i<r; i++) {
                if (S>>i&1) {
                    for (int j=0; j<c; j++) osen[i][j]^=1;
                }
            }
            int cnt=0;
            for (int i=0; i<c; i++) {
                int one=0;
                for (int j=0; j<r; j++) one+=osen[j][i];
                cnt+=max(one,r-one);
            }
            for (int i=0; i<r; i++) {
                if (S>>i&1) {
                    for (int j=0; j<c; j++) osen[i][j]^=1;
                }
            }
            res=max(res,cnt);
        }
        printf("%d\n",res);
    }
}
