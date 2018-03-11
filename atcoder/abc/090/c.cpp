#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    if (n == 1 && m == 1) puts("1");
    else if (n == 1) printf("%d\n", m-2);
    else if (m == 1) printf("%d\n", n-2);
    else printf("%lld\n", (ll)(n-2) * (ll)(m-2));
}

