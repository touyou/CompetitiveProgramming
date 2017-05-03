#include <cstdio>
#include <map>
#include <set>
using namespace std;
map<int, int> cnt;
set<int> list;
int p, a[1000000];
int main() {
    scanf("%d",&p);
    for (int i=0; i<p; i++) {
        scanf("%d",&a[i]);
        list.insert(a[i]);
    }
    int s=0, t=0, num=0, ans=p, n=list.size();
    for (;;) {
        while (t<p&&num<n) {
            if (cnt[a[t++]]++==0) num++;
        }
        if (num<n) break;
        ans=min(ans, t-s);
        if (--cnt[a[s++]]==0) num--;
    }
    printf("%d\n",ans);
}