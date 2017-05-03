#include <cstdio>
int l, a, b, c, d;
int max(int a, int b) { return a<b?b:a; }
int main() {
    scanf("%d%d%d%d%d",&l,&a,&b,&c,&d);
    int need = max((a+c-1)/c,(b+d-1)/d);
    printf("%d\n",l-need);
}
