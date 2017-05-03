#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int a[50], b[50];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=0; i<m; i++) scanf("%d",&b[i]);
    int res=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (b[j]%a[i]!=0) continue;
            res=max(res, b[j]/a[i]);
        }
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (b[j]%a[i]!=0) continue;
            if (b[j]/a[i]==res) ans++;
        }
    }
    printf("%d\n",ans);
}