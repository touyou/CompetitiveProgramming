#include <cstdio>
struct cood {int x, y;};
cood star[200], star2[1000];
int main() {
    int m,n;
    while (scanf("%d",&m)) {
        if (!m) break;
        for (int i=0; i<m; i++) {
            int x, y; scanf("%d%d",&x,&y);
            star[i]=(cood){x,y};
        }
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            int x, y; scanf("%d%d",&x,&y);
            star2[i]=(cood){x,y};
        }
        for (int i=0; i<n; i++) {
            int j;
            int dx=star2[i].x-star[0].x;
            int dy=star2[i].y-star[0].y;
            for (j=1; j<m; j++) {
                int x=star[j].x+dx;
                int y=star[j].y+dy;
                int k;
                for (k=0; k<n; k++) {
                    if (star2[k].x==x&&star2[k].y==y) break;
                }
                if (k==n) break;
            }
            if (j==m) {
                printf("%d %d\n",dx,dy);
                break;
            }
        }
    }
}
