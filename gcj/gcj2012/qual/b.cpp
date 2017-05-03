#include <cstdio>
int list[100];
int main() {
    int t; scanf("%d",&t);
    for (int ix=1; ix<=t; ix++) {
        int n, s, p; scanf("%d%d%d",&n,&s,&p);
        for (int i=0; i<n; i++) scanf("%d",&list[i]);
        int res=0;
        for (int i=0; i<n; i++) {
            int x=(list[i]+2)/3;
            if (list[i]==0&&p!=0) continue;
            if (x>=p) {
                res++;
            } else if (s>0&&p*3-list[i]<=4) {
                res++;
                s--;
            }
        }
        printf("Case #%d: %d\n",ix,res);
    }
}