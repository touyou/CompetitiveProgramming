#include <cstdio>
int n, m;
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        if ((i / n) % 2 == 0) printf("R");
        else printf("W");
    }
    puts("");
}
