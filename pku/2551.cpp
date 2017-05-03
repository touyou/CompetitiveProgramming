#include <cstdio>
int n;
int main() {
    while (scanf("%d",&n)!=EOF) {
        int s = 1, ans = 1;
        while (s % n != 0) {
            s = s * 10 + 1;
            ans++;
            s %= n;
        }
        printf("%d\n",ans);
    }
}
