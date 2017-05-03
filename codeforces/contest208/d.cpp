#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, p[50], a[5], b[5];
int main() {
    cin>>n;
    for (int i=0; i<n; i++) cin>>p[i];
    for (int i=0; i<5; i++) cin>>a[i];
    ll res=0;
    for (int i=0; i<n; i++) {
        res+=p[i];
        while (res>=a[0]) {
            ll use=upper_bound(a, a+5, res)-a-1;
            if (use<0) use=0;
            b[use]+=res/a[use];
            p[i]-=res/a[use]*a[use];
            res%=a[use];
        }
    }
    cout<<b[0];
    for (int i=1; i<5; i++) cout<<" "<<b[i];
    cout<<endl;
    cout<<res<<endl;
}