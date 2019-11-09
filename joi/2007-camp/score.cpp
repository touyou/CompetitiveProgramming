#include <cstdio>
#include <algorithm>
using namespace std;
struct score {
    int s, r, n;
};
bool comp1(const score& a, const score& b) {
    return a.s>b.s;
}
bool comp2(const score& a, const score& b) {
    return a.n<b.n;
}
score stu[100000];
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&stu[i].s);
        stu[i].n=i;
    }
    sort(stu, stu+n, comp1);
    int rank=1, cnt=0, bef=-1;
    for (int i=0; i<n; i++) {
        if (bef!=stu[i].s) {
            bef=stu[i].s;
            rank+=cnt;
            stu[i].r=rank;
            cnt=1;
        } else {
            cnt++;
            stu[i].r=rank;
        }
    }
    sort(stu, stu+n, comp2);
    for (int i=0; i<n; i++) {
        printf("%d\n",stu[i].r);
    }
}
