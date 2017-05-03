#include <cstdio>
#include <algorithm>
using namespace std;
int r[20001];
int main() {
    int n, s;
    while (scanf("%d%d",&n,&s)) {
        if (!n&&!s) break;
        for (int i=0; i<n; i++) scanf("%d",&r[i]);
        sort(r, r+n);
        int cnt=0;
        for (int i=n-1; i>0; i--) {
            if (r[i]>=s) cnt+=i;
            else {
                for (int j=i-1; j>=0; j--) {
                    if (r[i]+r[j]<=s) break;
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}