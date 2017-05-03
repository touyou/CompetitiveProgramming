#include <cstdio>

int n, a, b, l;

int main() {
    scanf("%d%d%d%d",&n,&a,&b,&l);
    double res = l;
    for (int i=0; i<n; i++) {
        double t = res / a;
        res = t * b;
    }
    printf("%f\n",res);
}