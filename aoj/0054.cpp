#include <cstdio>
int main() {
    int a,b,n;
    while (scanf("%d%d%d",&a,&b,&n)!=EOF) {
        int res=0;
        for (int i=0; i<n; i++) {
            a*=10;
            res+=a/b%10;
            a%=b;
        }
        printf("%d\n",res);
    }
}
