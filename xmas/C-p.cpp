#include <cstdio>
int main() {
    int t; scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int n, k; scanf("%d%d",&n,&k);
        if (k>n) printf("YES\n");
        else if (n%k==0) printf("YES\n");
        else printf("NO\n");
    }
}
