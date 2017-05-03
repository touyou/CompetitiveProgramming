#include <cstdio>
int col[1001][101];
int main() {
    int n, m, a;
    while (scanf("%d%d%d",&n,&m,&a)) {
        if (!n&&!m&&!a) break;
        for (int i=0; i<=1000; i++) for (int j=0; j<=100; j++) col[i][j]=0;
        for (int i=0; i<m; i++) {
            int h, p, q; scanf("%d%d%d",&h,&p,&q);
            col[h][p]=q;
            col[h][q]=p;
        }
        int pos=a;
        for (int i=1000; i>0; i--) {
            if (col[i][pos]!=0) {
                pos=col[i][pos];
            }
        }
        printf("%d\n",pos);
    }
}
