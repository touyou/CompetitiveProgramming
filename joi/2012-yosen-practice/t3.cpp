#include <cstdio>
int n, a, b, ra, rb;
int main() {
    scanf("%d",&n);
    ra=0; rb=0;
    for (int i=0; i<n; i++) {
        scanf("%d%d",&a,&b);
        if (a>b) ra++;
        else if (a<b) rb++;
    }
    printf("%d %d\n",ra,rb);
}
