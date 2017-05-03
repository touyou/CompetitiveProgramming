#include <cstdio>
#include <cmath>
int main() {
    int n, y;
    while (scanf("%d", &n)&&n!=0) {
        scanf("%d", &y);
        int b, r, t;
        double max = -10000;
        int res;
        for (int i=0; i<n; i++) {
            scanf("%d%d%d",&b,&r,&t);
            if (t == 1) {
                double ri = 1.0 + (double)y * (double)r / 100.0;
                if (ri > max) {
                    max = ri;
                    res = b;
                }
            } else {
                double ri = pow(1+(double)r/100, y);
                if (ri > max) {
                    max = ri;
                    res = b;
                }
            }
        }
        printf("%d\n",res);
    }
}
