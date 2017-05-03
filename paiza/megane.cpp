#include <cstdio>
int n, m, ax, ay;
int q[100][100], p[10][10];
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", &q[i][j]);
    scanf("%d", &m);
    for (int i=0; i<m; i++) for (int j=0; j<m; j++) scanf("%d", &p[i][j]);
    ax = ay = -1;
    for (int px=0; px<n; px++) {
        for (int py=0; py<n; py++) {
            bool flag = true;
            for (int i=0; i<m; i++) {
                for (int j=0; j<m; j++) {
                    if (q[px+i][py+j] != p[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) {
                ax = px; ay = py;
            }
        }
        if (ax >= 0 && ay >= 0) break;
    }
    printf("%d %d\n",ax,ay);
}
