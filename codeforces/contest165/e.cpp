#include <cstdio>
int ans[1000005];
int a[1000005];
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        ans[i]=-1;
    }
    for (int i=0; i<n; i++) {
        if (ans[i]==-1) {
            for (int j=0; j<n; j++) if (i!=j&&(a[i]&a[j])==0) {
                ans[i]=a[j];
                ans[j]=a[i];
                break;
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d%c",ans[i],i==n-1?'\n':' ');
    }
}
