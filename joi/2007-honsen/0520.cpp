#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
struct mob {
    int l, r, a, b;
    mob () {}
    mob (int l, int r, int a, int b) : l(l),r(r),a(a),b(b) {}
};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return a*b/gcd(a,b); }

vector<int> to[101];
mob mobs[101];
int n;

ll dfs(int id) {
    ll a=1, b=1;
    if (mobs[id].a) a=dfs(mobs[id].a);
    if (mobs[id].b) b=dfs(mobs[id].b);
    ll x=lcm(a*mobs[id].l, b*mobs[id].r);
    return x/mobs[id].r+x/mobs[id].l;
}

int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<101; i++) {
            to[i].clear();
        }
        for (int i=1; i<=n; i++) {
            int l, r, a, b; scanf("%d%d%d%d",&l,&r,&a,&b);
            mobs[i]=mob(l,r,a,b);
            if (a) to[a].push_back(i);
            if (b) to[b].push_back(i);
        }
        ll res=0;
        for (int i=1; i<=n; i++) {
            if (to[i].size()==0) {
                res=dfs(i);
                break;
            }
        }
        printf("%lld\n",res);
    }
}
