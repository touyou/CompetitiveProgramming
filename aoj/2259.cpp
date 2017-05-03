#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int m, n; scanf("%d%d",&m,&n);
    int M=-1;
    for (int i=0; i<m; i++) {
        int sum=0;
        for (int j=0; j<n; j++) {
            int s; scanf("%d",&s);
            sum+=s;
        }
        M=max(M,sum);
    }
    printf("%d\n",M);
}
