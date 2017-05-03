#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int n;
pair<int, int> p[50000];
int main() {
    while (scanf("%d",&n)) {
        if (n==0) break;
        for (int i=0; i<n; i++) {
            scanf("%d%d",&p[i].first,&p[i].second);
        }
        sort(p, p+n, greater<pair<int, int> >());
        int res=1, ymax=p[0].second;
        for (int i=1; i<n; i++) {
            if (ymax<p[i].second) {
                res++;
                ymax=p[i].second;
            }
        }
        printf("%d\n",res);
    }
}