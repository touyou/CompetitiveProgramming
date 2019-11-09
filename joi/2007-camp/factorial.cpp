#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n; scanf("%d",&n);
    int res, ans=1;
    for (int i=2; i<=n; i++) {
        res=0;
        while (n%i==0) {
            n/=i;
            res+=i;
        }
        ans=max(ans,res);
    }
    printf("%d\n",ans);
}
