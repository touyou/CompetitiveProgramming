#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int n; scanf("%d",&n);
    int cow[n];
    for (int i=0; i<n; i++) scanf("%d",&cow[i]);
    sort(cow, cow+n);
    ll dis=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) dis+=abs(cow[j]-cow[i]);
    }
    printf("%lld\n",dis*2);
}
