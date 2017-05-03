#include <cstdio>
#include <algorithm>
using namespace std;
int t, n;
int a[100];
int main() {
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int max_key=0, max_cnt=0;
        scanf("%d",&n);
        for (int j=0; j<n; j++) scanf("%d",&a[j]);
        sort(a, a+n);
        int state=a[0], cnt=1;
        for (int j=1; j<n; j++) {
            if (state!=a[j]) {
                if (max_cnt<cnt) {
                    max_cnt=cnt;
                    max_key=state;
                }
                state=a[j];
                cnt=1;
            } else {
                cnt++;
            }
        }
        if (max_cnt<cnt) {
            max_cnt=cnt;
            max_key=state;
        }
        printf("%d %d\n",max_key,max_cnt);
    }
}
