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

void solve() {
    int n, a, b, c; scanf("%d%d%d%d",&n,&a,&b,&c);
    int top[n];
    for (int i=0; i<n; i++) scanf("%d",&top[i]);
    sort(top, top+n, greater<int>());
    int res = 0;
    int cal = 0;
    for (int i=0; i<n; i++) {
        cal += top[i];
        res = max(res, (cal+c)/(a+b*(i+1)));
    }
    printf("%d\n", res);
}
int main() {
    solve();
    return 0;
}
