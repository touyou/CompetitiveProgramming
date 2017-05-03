#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, s, c, y, minc=100000;
ll res=0;
int main() {
    scanf("%d%d",&n,&s);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&c,&y);
        minc=min(minc+s,c);
        res += minc*y;
    }
    printf("%lld\n",res);
}
