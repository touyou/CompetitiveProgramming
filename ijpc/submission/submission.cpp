#include"grader.h"
typedef long long ll;
long long getT(int N, long long M) {
    if (N<3) {
        for (ll i=0; i<=M; i++) if (compare(i)) return i;
    }
    ll lb=0, ub=M+1;
    while (N>1&&ub-lb>0) {
        ll mid=(ub+lb)/2;
        if (compare(mid)) {
            ub=mid;
            N--;
        } else {
            lb=mid;
        }
    }
    if (ub-lb==1) return ub;
    if (lb!=0) lb++;
    while (lb<=M) {
        if (compare(lb)) return lb;
        lb++;
    }
}
