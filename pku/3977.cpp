#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
typedef long long ll;
ll input[36];
ll subset[1<<17];
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) {
            scanf("%lld",&input[i]);
        }
        int half=n/2;
        ll res=LLONG_MAX;
        int rcnt=36;
        for (int i=0; i<1<<half; i++) {
            for (int j=0; j<half; j++) {
                if (i>>j&1) subset[i]+=input[j];
            }
        }
        for (int i=0; i<1<<half; i++) {
        printf("%lld %d\n",res,rcnt);
    }
}
