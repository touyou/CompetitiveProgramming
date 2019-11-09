#include <cstdio>
#include <iostream>
using namespace std;
int par[10000];
void init(int n) {
    for (int i=0; i<n; i++) {
        par[i]=0;
    }
}
int t, n, m, a, b;
char mode;
int main() {
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        scanf("%d%d",&n,&m);
        init(n);
        bool flag=true;
        for (int i=0; i<m; i++) {
            cin>>mode; scanf("%d%d",&a,&b);
            if (mode=='D') {
                flag=false;
                if (par[a-1]==par[b-1]) {
                    par[b-1]^=1;
                }
            } else if (mode=='A') {
                if (flag) puts("Not sure yet.");
                else {
                    if (par[a-1]==par[b-1]) puts("In the same gang.");
                    else puts("In different gangs.");
                }
            }
        }
    }
}
