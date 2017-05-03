#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int len[50005];
int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%d",&len[i]);
        }
        int s=0, t=0;
        int res=0;
        memset(len,0,sizeof(len));
        while (t<n) {
            while (t<n&&len[t]<len[t+1]) {
                t++;
            }
            res=max(res,t-s-1);
            s=t;
        }
        printf("%d\n",res);
    }
}
