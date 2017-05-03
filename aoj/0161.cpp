#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct team { ll name, time; };
bool comp(const team& a, const team& b) { return a.time<b.time; };
team t[1000000];
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) {
            scanf("%lld",&t[i].name);
            int a,b,c,d,e,f,g,h;scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
            t[i].time=(a+c+e+g)*60+b+d+f+h;
        }
        sort(t, t+n, comp);
        printf("%lld\n%lld\n%lld\n",t[0].name,t[1].name,t[n-2].name);
    }
}
