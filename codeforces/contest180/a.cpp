#include <cstdio>
int n, m;
int cl[200];
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        int ni; scanf("%d",&ni);
        for (int j=0; j<ni; j++) {
            int a; scanf("%d",&a);
            cl[a-1]=i;
        }
    }
}