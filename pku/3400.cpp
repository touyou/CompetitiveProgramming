#include <cstdio>
#include <map>
#include <algorithm>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
int p[10];
P st[10];
int main() {
    int n, d;
    scanf("%d%d",&n,&d);
    for (int i=0; i<n; i++) {
        int px, v; scanf("%d%d",&px,&v);
        st[i]=P(px,v);
        p[i]=i;
    }
    int res=0;
    do {
        bool flag=false;
        int a=0, b=0, r=0;
        for (int i=0; i<n; i++) {
            int x=p[i];
            if (flag) {
                if (b-d>a) {
                    flag=false;
                    a+=st[x].f;
                } else {
                    b+=st[x].f;
                    r+=st[x].s;
                }
            } else {
                if (a-d>b) {
                    flag=true;
                    b+=st[x].f;
                    r+=st[x].s;
                } else {
                    a+=st[x].f;
                }
            }
        }
        res=max(res,r);
    } while (next_permutation(p,p+n));
    printf("%d\n",res);
}
