#include <cstdio>
#include <algorithm>
using namespace std;
int p[1001];
int main() {
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        int n; scanf("%d",&n);
        for (int i=0; i<n; i++) scanf("%d",&p[i]);
        sort(p, p+n);
        int res=0;
        if (n<3) {
            printf("%d\n",p[n-1]);
        } else if (n==3) {
            printf("%d\n",p[0]+p[1]+p[2]);
        } else {
            /* calc 1*/
            for (int i=1; i<n; i++) res+=p[i];
            res+=p[0]*(n-2);
            /* calc 2 */
            int temp=0;
            int b=p[0]+p[1]*2;
            int x=n-1;
            while (x>3) {
                temp+=b+p[x];
                x-=2;
            }
            if (x<3) temp+=p[x-1];
            else temp+=p[0]+p[1]+p[2];
            printf("%d\n",temp<res?temp:res);
        }
    }
}