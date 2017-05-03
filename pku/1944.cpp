#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int n, p; scanf("%d%d",&n,&p);
    int state[n]; // 0=1~2,1=2~3...n-1=n~1
    fill(state, state+n, 0);
    pair<int, int> in[p];
    for (int i=0; i<p; i++) {
        int s, e; scanf("%d%d",&s,&e);
        if (s>e) swap(s,e);
        in[i].first=s; in[i].second=e;
    }
    sort(in, in+p);
    for (int i=p-1; i>=0; i--) {
        int s=in[i].first, e=in[i].second;
        int r1=0, r2=0;
        for (int j=s-1; j<e-1; j++) r1+=state[j];
        for (int j=0; j<s-1; j++) r2+=state[j];
        for (int j=e-1; j<n; j++) r2+=state[j];
        if (e-s-r1<s+n-e-r2) {
            for (int j=s-1; j<e-1; j++) state[j]=1;
        } else {
            for (int j=0; j<s-1; j++) state[j]=1;
            for (int j=e-1; j<n; j++) state[j]=1;
        }
    }
    int res=0;
    printf("%d\n",res);
}
    for (int i=0; i<n; i++) res+=state[i];

