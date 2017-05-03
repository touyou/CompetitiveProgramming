#include <cstdio>
int main() {
    int cnt=0;
    int n; scanf("%d",&n);
    if (n==2) {
        puts("1");
        return 0;
    }
    while (n>2) {
        n/=2;
        cnt++;
    }
    printf("%d\n",cnt);
}
