#include <cstdio>
#include <algorithm>
using namespace std;
struct shift { int s, e; };
bool comp(const shift& s1, const shift& s2) {
    // if (s1.s==s2.s) return s1.e>s2.e;
    return s1.s < s2.s;
}
shift ss[25000];
int main() {
    int n, t;
    scanf("%d%d",&n,&t);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&ss[i].s,&ss[i].e);
    }
    sort(ss,ss+n,comp);
    int to=0, from=1, res=0, i=0;
    bool update;
    while (true) {
        update=false;
        for (; i<n&&ss[i].s<=from; i++) {
            to=max(to, ss[i].e);
            update=true;
        }
        res++;
        if (to>=t) {
            printf("%d\n",res);
            break;
        }
        if (i==n||!update) {
            puts("-1");
            break;
        }
        from=to+1;
    }
}
