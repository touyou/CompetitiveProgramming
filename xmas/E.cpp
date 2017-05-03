#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n, l, ac=0, wr=0, an=0, ti=0, ex=0, ru=0, er=0, pr=0;
    cin>>n>>l;
    for (int i=0; i<n; i++) {
        string in; cin >> in;
        if (in=="accepted") ac++;
        else if (in=="wrong") wr++;
        else if (in=="answer") an++;
        else if (in=="time-limit") ti++;
        else if (in=="exceeded") ex++;
        else if (in=="runtime") ru++;
        else if (in=="error") er++;
        else pr++;
    }
    if (n>=l*2) {
        if (pr == l) {
            printf("%d\n",ac);
        } else if (pr < l) {
            int diff = l - pr, extra = 0,wa,tle,re;
            if (wr!=an) {
                extra += abs(wr-an);
                wa=min(wr,an);
            }
            if (ti!=ex) {
                extra += abs(ti-ex);
                tle=min(ti,ex);
            }
            if (ru!=er) {
                extra += abs(ru-er);
                re=min(ru,er);
            }
            diff -= extra;
            if (wa+tle+re+ac-n>0&&wa+tle+re+ac-n<diff) diff = wa+tle+re+ac-n;
            else if (wa+tle+re+ac-n<diff) diff=0;
            if (diff < 0) diff = 0;
            printf("%d\n",ac-diff);
        } else {
            printf("hoge\n");
        }
    } else {
        printf("hoge\n");
    }
}
