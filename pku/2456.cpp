#include <cstdio>
#include <algorithm>
using namespace std;
int n, c;
int x[100000];
bool C(int d) {
    int last=x[0], j=1, cnt=1;
    for (int i=1; i<c; i++) {
        while (j<n&&x[j]<last+d) j++;
        if (j<n) {
            cnt++;
            last=x[j];
        }
    }
    return cnt==c;
}
int main() {
    scanf("%d%d",&n,&c);
    for (int i=0; i<n; i++) scanf("%d",&x[i]);
    sort(x, x+n);
    int lb=0, ub=1000000000;
    while (ub-lb>1) {
        int mid=(lb+ub)/2;
        if (C(mid)) {
            lb=mid;
        } else {
            ub=mid;
        }
    }
    printf("%d\n", lb);
}