#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll x, y;
vector<P> ans;
ll gcd(ll a, ll b) { return b==0?a:gcd(b,a%b); }
int main() {
    scanf("%lld/%lld",&x,&y);
    ll g=gcd(x,y);
    x/=g; y/=g;
    int t=2*x/y/y;
    while (true) {
        ll X=x*t, Y=y*t;
        ll sum=Y*(Y+1)/2;
        if (sum-X>Y) break;
        if (sum-X>0) ans.push_back(P(Y,sum-X));
        t++;
    }
    if (ans.size()==0) {
        puts("Impossible");
    } else {
        for (int i=0; i<ans.size(); i++) {
            printf("%lld %lld\n",ans[i].first,ans[i].second);
        }
    }
}