#include <cstdio>
int x[200], y[200];
int ri[200], le[200], lo[200], up[200];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (x[i]>x[j]&&y[i]==y[j]) {
                le[i]++; ri[j]++;
            } else if (x[i]<x[j]&&y[i]==y[j]) {
                le[j]++; ri[i]++;
            } else if (y[i]>y[j]&&x[i]==x[j]) {
                lo[i]++; up[j]++;
            } else if (y[i]<y[j]&&x[i]==x[j]) {
                lo[j]++; up[i]++;
            }
        }
    }
    int res=0;
    for (int i=0; i<n; i++) if (le[i]&&ri[i]&&lo[i]&&up[i]) res++;
    printf("%d\n",res);
}
