#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, k;
int a[100000];
bool C(int x) {
    ll sum=0;
    for (int i=0; i<n; i++) {
        if (a[i]>x) {
            if ((a[i]-x)%k) sum+=floor((double)(a[i]-x)/(double)k)+1;
            else sum+=(a[i]-x)/k;
        }
    }
    if (sum<=x) return true;
    else return false;
}
int main() {
    scanf("%d",&n);
    int l=-1, u=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        u=max(u, a[i]);
    }
    scanf("%d",&k);
    k--;
    if (k==0) {
        int ans=-1;
        for (int i=0; i<n; i++) ans=max(ans,a[i]);
        printf("%d\n",ans);
        return 0;
    }
    while (u-l>1) {
        int mid=(l+u)/2;
        if (C(mid)) u=mid;
        else l=mid;
    }
    printf("%d\n",u);
}
