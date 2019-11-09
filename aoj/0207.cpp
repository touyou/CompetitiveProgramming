#include <cstdio>
#include <cstring>
int block[100][100];
int w, h, xs, ys, xg, yg, n;
int d[2][4]={{0,0,-1,1},{-1,1,0,0}};
int main() {
    while (scanf("%d%d",&w,&h)) {
        if (!w&&!h) break;
        for (int i=0; i<100; i++) for (int j=0; j<100; j++) {
            block[i][j]=0;
        }
        scanf("%d%d%d%d%d",&xs,&ys,&xg,&yg,&n);
        for (int i=0; i<n; i++) {
            int c, d, x, y;
            scanf("%d%d%d%d",&c,&d,&x,&y);
            if (d) {
                for (int j=y-1; j<y+3; j++) {
                    for (int k=x-1; k<x+1; k++) {
                        block[j][k]=c;
                    }
                }
            } else {
                for (int j=x-1; j<x+3; j++) {
                    for (int k=y-1; k<y+1; k++) {
                        block[k][j]=c;
                    }
                }
            }
        }
        /*for (int i=0; i<h; i++) for (int j=0; j<w; j++) {
            printf("%d%c",block[i][j],j==w-1?'\n':' ');
        }*/
        if (dfs(xs,ys)) puts("OK");
        else puts("NG");
    }
}
