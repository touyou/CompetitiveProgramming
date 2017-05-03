#include <cstdio>
typedef long long ll;
int main() {
    ll A,B; scanf("%lld%lld",&A,&B);
    if (A==B||A-B==1||A-B==-1) printf("NO\n");
    else if (A>B) printf("%lld\n",B+1);
    else printf("%lld\n",A+1);
}
