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
    int pasta=INT_MAX, juice=INT_MAX;
    for (int i=0; i<3; i++) {
        int t; scanf("%d",&t);
        pasta = min(pasta, t);
    }
    for (int i=0; i<2; i++) {
        int t; scanf("%d", &t);
        juice = min(juice, t);
    }
    printf("%d\n", pasta+juice-50);
}
int main() {
    solve();
    return 0;
}
