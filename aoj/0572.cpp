#include <cstdio>
#include <algorithm>
using namespace std;
int an, bn;
int a[5000], b[5000];
int c(int num, int s) {
    for (int i=s; i<an; i++) {
        if (a[i]==num) return i;
    }
    return -1;
}
int main() {
    scanf("%d%d",&an,&bn);
    for (int i=0; i<an; i++) scanf("%d",&a[i]);
    for (int i=0; i<bn; i++) scanf("%d",&b[i]);
    int res=0;
    for (int i=0; i<an; i++) {
        for (int j=0; j<bn; j++) {
            if (a[i]==b[j]&&j==bn-1) {
                res=max(res, 1);
            } else if (a[i]==b[j]) {
                int pos=j+1, s=i+1;
                while (true) {
                    int ans=c(b[pos],s);
                    if (ans==-1) {
                        res=max(res,pos-j);
                        break;
                    } else {
                        pos++;
                        s=ans+1;
                    }
                }
            }
        }
    }
    printf("%d\n",res);
}
