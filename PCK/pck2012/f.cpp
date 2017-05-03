#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,r;
int moji[100000];
ll kai[100001];
int bit[100001];
int sum(int i) {
    int s = 0;
    while (i>0) {
        s+=bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, int x) {
    while (i<=n) {
        bit[i]+=x;
        i += i & -i;
    }
}
int main() {
    kai[0]=1;
    for (int i=1; i<=100000; i++) {
        kai[i]=(kai[i-1]*i)%mod;
    }
    while (scanf("%d",&n)) {
        if (!n) break;
        memset(bit, 0, sizeof(bit));
        scanf("%d",&r);
        for (int i=0; i<n; i++) moji[i]=i;
        for (int i=0; i<r; i++) {
            int s,t; scanf("%d%d",&s,&t);
            swap(moji[s-1],moji[t-1]);
        }
        ll res=0;
        for (int i=0; i<n; i++) {
            int x=kai[n-i-1];
            int bef=moji[i]-sum(moji[i]);
            if (bef<0) bef=0;
            add(moji[i]+1,1);
            res=(res+(bef*x)%mod)%mod;
        }
        printf("%d\n",res);
    }
}
