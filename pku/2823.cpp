#include <cstdio>
const int MAX_N = 1000000;
int n, k;
int a[MAX_N];

int min[MAX_N], max[MAX_N];
int deq1[MAX_N], deq2[MAX_N];
int main() {
    while (scanf("%d%d",&n,&k)!=EOF) {
        for (int i=0; i<n; i++) scanf("%d",&a[i]);
        int s=0, t=0;
        for (int i=0; i<n; i++) {
            while (s < t && a[deq1[t-1]] >= a[i]) t--;
            deq1[t++] = i;
            if (i - k + 1 >= 0) {
                min[i - k + 1] = a[deq1[s]];
                if (deq1[s] == i - k + 1) {
                    s++;
                }
            }
        }
        s=0; t=0;
        for (int i=0; i<n; i++) {
            while (s < t && a[deq2[t-1]] <= a[i]) t--;
            deq2[t++] = i;
            if (i - k + 1 >= 0) {
                max[i - k + 1] = a[deq2[s]];
                if (deq2[s] == i - k + 1) {
                    s++;
                }
            }
        }
        for (int i=0; i<=n-k; i++) printf("%d%c",min[i],i==n-k?'\n':' ');
        for (int i=0; i<=n-k; i++) printf("%d%c",max[i],i==n-k?'\n':' ');
    }
}
