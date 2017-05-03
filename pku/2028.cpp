#include <cstdio>
int n, q;
int cnt[101];
int main() {
    while (scanf("%d%d",&n,&q)) {
        if (!n&&!q) break;
        for (int i=0; i<101; i++) cnt[i]=0;
        for (int i=0; i<n; i++) {
            int m; scanf("%d",&m);
            for (int j=0; j<m; j++) {
                int day; scanf("%d",&day);
                cnt[day-1]++;
            }
        }
        int rcnt=0, res=0;
        for (int i=0; i<101; i++) {
            if (cnt[i]>=q&&rcnt<cnt[i]) {
                res=i+1;
                rcnt=cnt[i];
            }
        }
        printf("%d\n",res);
    }
}
