#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n, a1, a2, m;
int d[500];
int main() {
    scanf("%d",&n);
    a1=0; m=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&d[i]);
        a1+=d[i];
        m=max(m, d[i]);
    }
    if (n==1) a2=a1;
    else if (n==2) {
        a2=abs(d[1]-d[0]);
    } else if (n==3) {
        if (d[0]+d[1]>=d[2]&&d[0]+d[2]>=d[1]&&d[1]+d[2]>=d[0]) {
            a2=0;
        } else {
            a2=m*2-d[0]-d[1]-d[2];
        }
    } else {
        if (m*2-a1<0) a2=0;
        else a2=m*2-a1;
    } 
    printf("%d\n%d\n",a1,a2);
}