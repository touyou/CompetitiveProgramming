#include <cstdio>
int main() {
    int n, cn=1;
    while (scanf("%d",&n)) {
        if (!n) break;
        bool even=false;
        n *= 3;
        if (n % 2 == 0) even = true;
        if (even) n /= 2;
        else n = (n + 1) / 2;
        n *= 3;
        n /= 9;
        if (even) printf("%d. even %d\n",cn++,n);
        else printf("%d. odd %d\n",cn++,n);
    }
}
