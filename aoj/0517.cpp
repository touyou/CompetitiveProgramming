#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int card[100000];
int main() {
    while (scanf("%d%d",&n,&k)) {
        if (!n&&!k) break;
        for (int i=0; i<k; i++) scanf("%d",&card[i]);
        sort(card, card+k);
        int res=0, cnt=1;
        if (card[0]) {
            for (int i=1; i<k; i++) {
                if (card[i]-card[i-1]==1) cnt++;
                else {
                    res=max(res,cnt);
                    cnt=1;
                }
            }
            printf("%d\n",max(res,cnt));
        } else {
            int flag=1, pos=0;
            for (int i=2; i<k; i++) {
                if (card[i]-card[i-1]==1) {
                    cnt++;
                } else if (flag&&card[i]-card[i-1]==2) {
                    pos=i; flag=0;
                    cnt+=2;
                } else if (card[i]-card[i-1]==2) {
                    res=max(res,cnt);
                    cnt=1; i=pos; flag=1;
                } else {
                    res=max(res,cnt);
                    cnt=1; flag=1;
                }
            }
            printf("%d\n",max(res,cnt));
        }
    }
}
