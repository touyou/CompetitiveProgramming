#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int t; scanf("%d",&t);
    int n;
    for (int ix=0; ix<t; ix++) {
        scanf("%d",&n);
        int store[n];
        for (int i=0; i<n; i++) scanf("%d",&store[i]);
        sort(store, store+n);
        printf("%d\n",(store[n-1]-store[0])*2);
    }
}
