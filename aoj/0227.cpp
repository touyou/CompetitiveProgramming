#include <cstdio>
#include <algorithm>
using namespace std;
bool comp(const int& a, const int& b) {
    return a>b;
}
int n, m;
int p[1000];
int main() {
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m) break;
        for (int i=0; i<n; i++) {
            scanf("%d",&p[i]);
        }
        sort(p,p+n,comp);
        for (int i=m-1; i<n; i+=m) {
            p[i]=0;
        }
        int res=0;
        for (int i=0; i<n; i++) {
            res+=p[i];
        }
        printf("%d\n",res);
    }
}
