#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> P;
static const double PI = 6*asin( 0.5 );
ll dfs(int s, int bef, int cnt, int n, int day[]) {
    ll res = 0;
    if (s == n) return 1;
    if (day[s]==0) {
        for (int i=1; i<=3; i++) {
            if (bef==i&&cnt==2) continue;
            else if (bef!=i) res += dfs(s+1, i, 1, n, day);
            else res += dfs(s+1, i, cnt+1, n, day);
        }
    } else {
        if (bef==day[s]&&cnt==2) return 0;
        else if (bef!=day[s]) res += dfs(s+1, day[s], 1, n, day);
        else res += dfs(s+1, day[s], cnt+1, n, day);
    }
    return res;
}
void solve() {
    int n, k, a, b; scanf("%d%d",&n,&k);
    int day[n];
    fill(day, day+n, 0);
    for (int i=0; i<k; i++) {
        scanf("%d%d",&a,&b);
        day[a-1]=b;
    }
    ll res = 0;
    if (day[0]==0) {
        for (int i=1; i<=3; i++) {
            res += dfs(1, i, 1, n, day);
        }
    } else {
        res += dfs(1, day[0], 1, n, day);
    }
    printf("%lld\n",res%10000);
}
int main() {
    solve();
    return 0;
}
