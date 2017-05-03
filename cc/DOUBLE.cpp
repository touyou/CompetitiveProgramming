#include <cstdio>
int main() {
    int t; scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int n; scanf("%d",&n);
        if (n&1) printf("%d\n",n-1);
        else printf("%d\n",n);
    }
}
