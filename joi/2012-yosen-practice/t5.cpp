#include <cstdio>
#define mod 100000
typedef long long ll;
int n;
ll res=1;
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        res = res*3%mod;
    }
    printf("%lld\n",res);
}
