#include <cstdio>
int cnt[100];
int main() {
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF) {
        for (int i=0; i<100; i++) cnt[i]=0;
        cnt[a-1]++; cnt[b-1]++;
        while (scanf("%d%d",&a,&b)) {
            if (!a&&!b) break;
            cnt[a-1]++; cnt[b-1]++;
        }
        int odd=0;
        for (int i=0; i<100; i++) {
            if (cnt[i]%2!=0) odd++;
        }
        if (odd==2) puts("OK");
        else puts("NG");
    }
}
