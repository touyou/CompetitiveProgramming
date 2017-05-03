#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#include <map>
#define inf (double)LONG_MAX/2
using namespace std;
typedef pair<double, int> P;
int n, s, g, l[200002], r[200002];
double d[200002];
double calc(int x1, int x2, int y1, int y2) {
    return sqrt(abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2));
}
int main() {
    scanf("%d%d%d",&n,&s,&g);
    for (int i=0; i<=n; i++) scanf("%d%d",&l[i],&r[i]);
    l[0]=r[0]=s;
    l[n]=r[n]=g;
    printf("%f\n",d[n]);
}