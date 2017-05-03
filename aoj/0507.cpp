#include <cstdio>
#include <algorithm>
using namespace std;
int ans[1000];
int pos;
void func(int res, int ub) {
    if (res==0) {
        for (int i=0; ;i++) {
            printf("%d%c",ans[i],ans[i+1]==0?'\n':' ');
            if (ans[i+1]==0) break;
        }
    } else {
        for (int i=min(res,ub); i>=1; i--) {
            ans[pos]=i;
            pos++;
            func(res-i,i);
            pos--;
            ans[pos]=0;
        }
    }
}
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        func(n,n);
    }
}
