#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_L=100000;
int l, deq[2*MAX_L-1];
void init(int l_) {
    l=1;
    while (l<l_) l*=2;
    for (int i=0; i<2*l-1; i++) deq[i]=1;
}
void update(int a, int b, int k, int left, int right, int c) {
    if (right <= a || b <= left) return ;
    if (k>=l-1) {
        deq[k]=1<<c;
        return ;
    }
    update(a,b,k*2+1,left,(left+right)/2,c);
    update(a,b,k*2+2,(left+right)/2,right,c);
    deq[k]=deq[k*2+1]|deq[k*2+2];
}
int query(int a, int b, int k, int left, int right) {
    if (right <= a || b <= left) return 0;
    if (a <= left && right <= b)
        return deq[k];
    else
        return query(a,b,2*k+1,left,(left+right)/2)|query(a,b,2*k+2,(left+right)/2,right);
}
int main() {
    int t, o; scanf("%d%d%d",&l,&t,&o);
    init(l);
    for (int i=0; i<o; i++) {
        char mode; cin>>mode;
        int a,b,c;
        if (mode=='C') {
            scanf("%d%d%d",&a,&b,&c);
            if (a>b) swap(a,b);
            update(a-1,b,0,0,l,c-1);
        } else {
            scanf("%d%d",&a,&b);
            if (a>b) swap(a,b);
            int ans=query(a-1,b,0,0,l);
            printf("%d\n",__builtin_popcount(ans));
        }
    }
}
