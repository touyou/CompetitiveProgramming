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
    int n; scanf("%d", &n);
    vector<P> team(n), res(n);
    for (int i=0; i<n; i++) {
        team[i].first = 0;
        team[i].second = i+1;
    }
    for (int i=0; i<n*(n-1)/2; i++) {
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        if (c > d) {
            team[a-1].first += 3;
        } else if (c < d) {
            team[b-1].first += 3;
        } else {
            team[a-1].first++;
            team[b-1].first++;
        }
    }
    sort(team.begin(), team.end());
    int place = 0, bef = INT_MAX, temp=0;
    for (int i=n-1; i>=0; i--) {
        if (bef != team[i].first) {
            place+=temp+1;
            temp=0;
            res[i].second = place;
        } else {
            temp++;
            res[i].second = place;
        }
        bef = team[i].first;
        res[i].first = team[i].second;
    }
    sort(res.begin(), res.end());
    for (int i=0; i<n; i++) printf("%d\n",res[i].second);
}

int main() {
    solve();
    return 0;
}
