#include <stdio.h>
#include <math.h>

int main() {
    int xa, xb, xc;
    int ya, yb, yc;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    double xab = (double)(xb - xa);
    double yab = (double)(yb - ya);
    double xac = (double)(xc - xa);
    double yac = (double)(yc - ya);
    printf("%.1lf\n", fabs(xab*yac - yab*xac) / 2.0);
    return 0;
}
