#include <cstdio>
#include <cstring>
#include <vector>
#define MOD 4207849484
using namespace std;
typedef long long ll;
int n, m;
ll res;
char str[1000];
void solve() {
    
}
int main() {
    scanf("%d",&n);
    for (int ix=1; ix<=n; ix++) {
        scanf("%d",&m);
        getline(str);
        res=0;
        solve();
        printf("Case #%d: %lld\n",ix,res);
    }
}
