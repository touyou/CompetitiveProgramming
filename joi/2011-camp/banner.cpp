#include <cstdio>
typedef long long ll;
int ban[400][400];
int brow[400], grow[400], wrow[400];
int bcol[400], gcol[400], wcol[400];
int main() {
    int h, w; scanf("%d%d",&h,&w);
    for (int i=0; i<h; i++) for (int j=0; j<w; j++) 
        scanf("%d",&ban[i][j]);
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (ban[i][j]==1) {
                grow[i]++;
                gcol[j]++;
            } else if (ban[i][j]==2) {
                wrow[i]++;
                wcol[j]++;
            } else {
                brow[i]++;
                bcol[j]++;
            }
        }
    }
    ll res=0;
    for (int i=0; i<h; i++) for (int j=0; j<w; j++) {
        if (ban[i][j]==0) {
            res+=grow[i]*wcol[j]+gcol[j]*wrow[i];
        } else if (ban[i][j]==1) {
            res+=brow[i]*wcol[j]+bcol[j]*wrow[i];
        } else {
            res+=brow[i]*gcol[j]+bcol[j]*grow[i];
        }
    }
    printf("%lld\n",res/2);
}
