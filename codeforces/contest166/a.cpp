#include <cstdio>
#include <algorithm>
using namespace std;
struct S {
    int p, t;
    S () {}
    S (int p, int t) : p(p), t(t) {}
};
bool comp(const S& a, const S& b) {
    if (a.p!=b.p) return a.p>b.p;
    return a.t<b.t;
}
S score[50];
int main() {
    int n, k; scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) scanf("%d%d",&score[i].p,&score[i].t);
    sort(score, score+n, comp);
    int res=0;
    int rank=0;
    int cnt=0;
    S bef=S(-1,-1);
    for (int i=0; i<n; i++) {
        if (bef.p!=score[i].p||bef.t!=score[i].t) {
            if (rank+cnt>=k&&k>=rank) {
                res=cnt;
                break;
            }
            bef=score[i];
            rank+=cnt;
            cnt=1;
        } else {
            cnt++;
        }
    }
    if (rank+cnt>=k&&k>=rank) res=cnt;
    printf("%d\n",res);
}
