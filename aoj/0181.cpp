#include <cstdio>
int m, n;
int book[100];
bool C(int k) {
    int sum=0, cnt=1;
    for (int i=0; i<n; i++) {
        sum+=book[i];
        if (book[i]>k) return false;
        if (sum>k) {
            sum=book[i];
            cnt++;
        }
    }
    if (cnt>m) return false;
    return true;
}
int main() {
    while (scanf("%d%d",&m,&n)) {
        if (!m&&!n) break;
        for (int i=0; i<n; i++) scanf("%d",&book[i]);
        int l=1, u=1500001;
        while (u-l>1) {
            int mid=(u+l)/2;
            if (C(mid)) {
                u=mid;
            } else {
                l=mid;
            }
        }
        printf("%d\n",u);
    }
}
