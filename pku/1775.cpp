#include <cstdio>
typedef long long ll;
bool res[1000001];
int main() {
    res[0]=1;
    int f=1;
    for (int i=0; i<10; i++) {
        if (i) f*=i;
        for (int i=1000000-f; i>=0; i--) if (res[i]) res[i+f]=1;
    }
    res[0]=0;
    int n;
    while (scanf("%d",&n)) {
        if (n<0) break;
        if (res[n]) puts("YES");
        else puts("NO");
    }
}