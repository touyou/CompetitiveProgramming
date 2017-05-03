#include <cstdio>
int data[200][200];
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        int s; scanf("%d", &s);
        for (int j=0; j<s; j++) {
            scanf("%d",&data[i][j]);
        }
    }
    
