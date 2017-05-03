#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll n;
vector<P> res;
int main() {
    scanf("%lld",&n);
    int lb=0, ub=1;
    ll sum=0;
    while (true) {
        while (sum<n&&(ll)ub*(ll)ub<=n) {
            sum+=(ll)ub*ub;
            ub++;
        }
        if (sum<n) break;
        if (sum==n) res.push_back(P(lb+1,ub-1));
        lb++;
        sum-=(ll)lb*(ll)lb;
    }
    int rs=res.size();
    printf("%d\n",rs);
    for (int i=0; i<rs; i++) {
        printf("%d ",res[i].second-res[i].first+1);
        for (int j=res[i].first; j<=res[i].second; j++) {
            printf("%d%c",j,j==res[i].second?'\n':' ');
        }
    }
}