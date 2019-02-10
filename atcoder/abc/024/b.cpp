#include <bits/stdc++.h>
using namespace std;

int n, t;
int res;

int main() {
    scanf("%d%d", &n, &t);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > t) res += t;
        else res += a[i] - a[i - 1];
    }
    printf("%d\n", res + t);
}
