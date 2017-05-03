#include <cstdio>
int main() {
    int n, x, y;
    scanf("%d%d%d",&n,&x,&y);
    int come=(n*y+99)/100;
    if (come>=x) printf("%d\n",come-x);
    else puts("0");
}
