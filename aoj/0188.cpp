#include <cstdio>
#include <cmath>
int n, x;
int a[100];
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) scanf("%d",&a[i]);
        scanf("%d", &x);
        int lb=0, ub=n-1, res=0;
        while (ub>=lb) {
            res++;
            int mid=floor((lb+ub)/2);
            if (a[mid]<x) {
                lb=mid+1;
            } else if (a[mid]>x) {
                ub=mid-1;
            } else {
                break;
            }
        }
        printf("%d\n",res);
    }
}
