#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll bit0[100005], bit1[100005], n;
ll sum(ll *bit, int i) {
    ll s=0;
    while (i>0) {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll *bit, int i, int x) {
    while (i<=n) {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int a, b; scanf("%d%d",&a,&b);
        add(bit0,a,-1*(a-1));
        add(bit1,a,1);
        add(bit0,b+1,b);
        add(bit1,b+1,-1*b);
    }
    ll res=0, mp=0, bef=sum(bit0,1)+sum(bit1,1);
    for (int i=2; i<=100001; i++) {
        ll temp=sum(bit0,i)+sum(bit1,i)*i;
        res=max(res,temp-bef);
        bef=temp;
    }
    printf("%lld\n",);
