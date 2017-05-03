#include <cstdio>
#include <algorithm>
using namespace std;
int s[8];
int c[8][8];
int n;
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        s[i]=i;
        for (int j=0; j<n; j++) {
            scanf("%d",&c[i][j]);
        }
    }
    int res=0;
    do {
        int x[n];
        for (int i=0; i<n; i++) x[i]=s[i];
        
    } while (next_permutation(s, s+n));
    printf("%d\n",res);
}
