#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int l, n, ans, temp, ln, rn;
int a[5000];
set<int> x;
int main() {
    scanf("%d%d",&l,&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        x.insert(a[i]);
    }
    sort(a, a+n);
    ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            temp = l - (a[i] + a[j]);
            if (temp <= a[j]) continue;
            set<int>::iterator iti = x.find(temp);
            if (iti != x.end()) ans++;
        }
    }
    printf("%d\n",ans);
}
