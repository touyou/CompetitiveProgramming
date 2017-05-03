#include <cstdio>
#include <set>
using namespace std;
set<int> used;
int r[200000];
int main() {
    int a, b, m, r0; scanf("%d%d%d%d",&a,&b,&m,&r0);
    r[0]=r0;
    used.insert(r0);
    int f=-1;
    for (int i=1; i<m*2; i++) {
        r[i]=(a*r[i-1]+b)%m;
        if (used.find(r[i])!=used.end()) {
            f=r[i];
            break;
        }
        used.insert(r[i]);
    }
    if (f==-1) {
        puts("0");
        return 0;
    }
    int res=0;
    bool flag=false;
    for (int i=0; i<m*2; i++) {
        if (!flag&&r[i]==f) {
            flag=true;
        } else if (flag&&r[i]==f) {
            break;
        }
        if (flag) res++;
    }
    printf("%d\n",res);
}
