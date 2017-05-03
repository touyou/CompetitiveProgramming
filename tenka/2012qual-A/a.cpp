#include <cstdio>
typedef long long ll;
int n;
ll usa[50];
int main() {
    scanf("%d",&n);
    // n-2に生まれているだけ増える
    usa[0]=usa[1]=1;
    for (int i=2; i<=45; i++) {
        usa[i]=usa[i-1]+usa[i-2];
    }
    printf("%lld\n",usa[n]);
}
