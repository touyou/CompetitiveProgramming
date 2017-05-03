#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        ll sum=1;
        if (n==1) {
            puts("deficient number");
            continue;
        }
        for (int i=2; i*i<=n; i++) {
            if (n%i==0) {
                if (i!=n/i) sum+=n/i+i;
                else sum+=i;
            }
        }
        if (sum>n) puts("abundant number");
        else if (sum<n) puts("deficient number");
        else puts("perfect number");
    }
}
