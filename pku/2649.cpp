#include <cstdio>
#include <cmath>
int gcd(int a, int b) {
    return b?gcd(b,a%b):a;
}
int main() {
    int n, m;
    int sz=
    while (scanf("%d%d",&n,&m)!=EOF) {
        int x=m;
        for (int i=n; i>1; i--) {
            x /= gcd(x, i);
            if (x==1) break;
        }
        if (x!=1) printf("%d does not divide %d!\n",m,n);
        else printf("%d divides %d!\n",m,n);
    }
}
