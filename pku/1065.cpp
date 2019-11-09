#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 20000;
struct wood { int w, l; };
bool comp(const wood& a, const wood& b) {
    return a.w<b.w;
}
int ans[5000];
wood stick[5000];
int main() {
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        int n; scanf("%d",&n);
        for (int i=0; i<n; i++) scanf("%d%d",&stick[i].w,&stick[i].l);
        sort(stick, stick+n, comp);
        fill(ans, ans+n, INF);
        int x=1; ans[0]=stick[0].l;
        for (int i=1; i<n; i++) {
            sort(ans, ans+x);
            int pos=upper_bound(ans, ans+n, stick[i].l)-ans;
            if (pos==0) ans[x++]=stick[i].l;
            else ans[pos-1]=stick[i].l;
        }
        printf("%d\n",lower_bound(ans,ans+n,INF)-ans);
    }
}
