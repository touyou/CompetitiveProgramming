#include <stdio.h>
#include <math.h>
int main() {
    int n;
    int a[120];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int bug_count = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        bug_count += a[i];
        count++;
    }
    printf("%d\n", (int)ceil((double)bug_count / (double)count));
    return 0;
}
